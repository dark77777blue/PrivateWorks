#include <QHostAddress>
#include "ui_widget.h"
#include "Udpserver.h"
#include <QDebug>
#include <math.h>

Udpserver::Udpserver(QString addr, QWidget *parent, Qt::WindowFlags f) : QWidget(parent, f), ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("UDP Server"));


    this->port = 5555;
    this->isStarted = false;
    this->udpSocket = new QUdpSocket(this);
    this->address.setAddress(addr);
 /*
    //this->timer = new QTimer(this);
    //connect(this->timer, SIGNAL(timeout()), this, SLOT(timeout()));
    //this->timer->start(50);
*/

//----------------------------��������------------------------------
    this->grabGesture(Qt::PanGesture);  //ʹ��Pan�������������pan(��)�������Ʊ������⽫ʹUdpserver��ΪQGestureEvents��Ŀ�ꡣ
    this->grabGesture(Qt::PinchGesture);//�����������pinch(��)���Ʊ������⽫ʹUdpserver��ΪQGestureEvents��Ŀ�ꡣ
    this->grabGesture(Qt::SwipeGesture);
    this->grabGesture(Qt::TapAndHoldGesture);   //����
    this->grabGesture(Qt::TapGesture);  //���
    //qDebug() << "-----------------";

//----------------------------����������------------------------------
    this->m_sensor = new QAccelerometer(this);
    this->m_sensor->addFilter(this);
    connect(this->m_sensor, SIGNAL(readingChanged()), this, SLOT(checkReading()));
    this->m_sensor->start();
    qDebug() << "availableDataRates = " << this->m_sensor->availableDataRates();
    qDebug() << "bufferSize = " << this->m_sensor->bufferSize();
    qDebug() << "outputRange = " << this->m_sensor->outputRange();

}


Udpserver::~Udpserver()
{
    delete ui;
}

/*
void Udpserver::StartBtnClicked()
{
    if(!this->isStarted){
        this->StartBtn->setText(tr("ֹͣ"));
        this->timer->start(1000);
        this->isStarted = true;
    }else{
        this->StartBtn->setText(tr("��ʼ"));
        this->isStarted = false;
        this->timer->stop();
    }
}
*/

/*
void Udpserver::timeout()
{
    QByteArray strData;
    strData.append(QByteArray(1, STX)); //??;
    strData.append(QByteArray(1, POS)); //????
    strData.append(QString::number(x));
    strData.append(QByteArray(1, ':')); //???
    strData.append(QString::number(y));
    strData.append(QByteArray(1, ETX)); //???

    //this->udpSocket->writeDatagram(strData, strData.count(), QHostAddress::Broadcast, port);

    //QHostAddress address;
    //address.setAddress("192.168.137.6");    //������Ҫ�����ݷ��͵���IP��ַ
    this->udpSocket->writeDatagram(strData, this->address, port);
}
*/

void Udpserver::sendPos(void)   //send offset
{
    QByteArray strData;
    strData.append(QByteArray(1, STX)); //??;
    strData.append(QByteArray(1, POS)); //????
    strData.append(QString::number(x));
    strData.append(QByteArray(1, ':')); //???
    strData.append(QString::number(y));
    strData.append(QByteArray(1, ETX)); //???

    //this->udpSocket->writeDatagram(strData, strData.count(), QHostAddress::Broadcast, port);

    //QHostAddress address;
    //address.setAddress("192.168.137.6");    //������Ҫ�����ݷ��͵���IP��ַ
    this->udpSocket->writeDatagram(strData, address, port);
}










void Udpserver::on_Button_Left_clicked()    //??
{
    QByteArray arr;
    arr.resize(3);
    arr[0] = STX;
    arr[1] = LCLICK;
    arr[2] = ETX;

    //this->udpSocket->writeDatagram(arr, arr.count(), QHostAddress::Broadcast, this->port);
    //QHostAddress address;
    //address.setAddress("192.168.137.6");    //������Ҫ�����ݷ��͵���IP��ַ
    this->udpSocket->writeDatagram(arr, address, this->port);
}

void Udpserver::on_Button_Right_clicked()   //??
{
    QByteArray arr;
    arr.resize(3);
    arr[0] = STX;
    arr[1] = RCLICK;
    arr[2] = ETX;

    //this->udpSocket->writeDatagram(arr, arr.count(), QHostAddress::Broadcast, this->port);

    //QHostAddress address;
    //address.setAddress("192.168.137.6");    //������Ҫ�����ݷ��͵���IP��ַ
    this->udpSocket->writeDatagram(arr, address, this->port);
}

void Udpserver::on_power_release()  //�ػ���ť
{
    //qDebug() << "on_power_release";
    QByteArray arr;
    arr.resize(3);
    arr[0] = STX;
    arr[1] = POWER_OFF;
    arr[2] = ETX;
    this->udpSocket->writeDatagram(arr, address, this->port);
}

void Udpserver::on_left_release()
{
    QByteArray arr;
    arr.resize(3);
    arr[0] = STX;
    arr[1] = LCLICK;
    arr[2] = ETX;
    this->udpSocket->writeDatagram(arr, address, this->port);
}

void Udpserver::on_right_release()
{
    QByteArray arr;
    arr.resize(3);
    arr[0] = STX;
    arr[1] = RCLICK;
    arr[2] = ETX;

    this->udpSocket->writeDatagram(arr, address, this->port);
}

/******************************����Ϊ���Ʋ���***********************************/
void Udpserver::swipeTriggered(QSwipeGesture *gesture)
{

}

void Udpserver::panTriggered(QPanGesture *gesture)
{
    //qDebug() << "delta = " << gesture->delta();
    //qDebug() << "acceleration = " << gesture->acceleration();

    QPointF delta = gesture->delta();
    //QPointF delta = gesture->lastOffset();
    //QPointF delta = gesture->offset();
    this->x = delta.x();
    this->y = delta.y();
    this->sendPos();



}

void Udpserver::pinchTriggered(QPinchGesture *gesture)
{
    QPinchGesture::ChangeFlags changeFlags = gesture->changeFlags();

    if(changeFlags & QPinchGesture::ScaleFactorChanged){
        qreal value = gesture->scaleFactor();
        qreal zoom = value * 0.5;
        //if(zoom < 2 && zoom >0.5){
        //    setZoomFactor(zoom);
        //}
    }
}

void Udpserver::tapTriggered(QTapGesture *gesture)
{
    //this->on_Button_Left_clicked();
}

void Udpserver::tap_hold_Triggered(QTapAndHoldGesture *gesture)
{

}

bool Udpserver::gestureEvent(QGestureEvent *e)
{
    if(QGesture *swipe = e->gesture(Qt::SwipeGesture)){
        swipeTriggered(static_cast<QSwipeGesture *>(swipe));
    }else if(QGesture *pan = e->gesture(Qt::PanGesture)){
        panTriggered(static_cast<QPanGesture *>(pan));
    }else if(QGesture *pinch = e->gesture(Qt::PinchGesture)){
        pinchTriggered(static_cast<QPinchGesture *>(pinch));
    }else if(QGesture *tap = e->gesture(Qt::TapGesture)){
        tapTriggered(static_cast<QTapGesture *>(tap));
    }else if(QGesture *tap_hold = e->gesture(Qt::TapAndHoldGesture)){
        tap_hold_Triggered(static_cast<QTapAndHoldGesture *>(tap_hold));
    }

    return true;
}

bool Udpserver::event(QEvent *e)
{
    if(e->type() == QEvent::Gesture){
        return gestureEvent(static_cast<QGestureEvent *>(e));
    }
    return QWidget::event(e);
}


bool Udpserver::filter(QAccelerometerReading *reading)  //����һ���˷�����֪Ϊʲô����ʱӰ��
{
    /*
    qreal x = reading->x();
    qreal y = reading->y();
    qreal z = reading->z();

    ui->lbl_x->setText("x: " + QString::number(x));
    ui->lbl_y->setText("y: " + QString::number(y));
    ui->lbl_z->setText("z: " + QString::number(z));

    if(fabs(this->x - x) > 1 || fabs(this->y - y) > 1){
        this->x = 0 - x * 2;    //��������
        this->y = y * 2;
        this->sendPos();
    }
*/

}

void Udpserver::checkReading()      //��������
{
    qreal x = this->m_sensor->reading()->x();
    qreal y = this->m_sensor->reading()->y();
    qreal z = this->m_sensor->reading()->z();

    ui->lbl_x->setText("x: " + QString::number(x));
    ui->lbl_y->setText("y: " + QString::number(y));
    ui->lbl_z->setText("z: " + QString::number(z));

    if(fabs(this->x - x) > 1 || fabs(this->y - y) > 1){
        this->x = 0 - x * 3;    //��������
        this->y = y * 3;
        this->sendPos();
    }
}







