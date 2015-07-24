#include "mouse_dialog.h"
#include "ui_mouse_dialog.h"
#include <QPalette>
#include <QPainter>
#include <QLinearGradient>
#include <QDebug>
#include <math.h>

Mouse_Dialog::Mouse_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mouse_Dialog)
{
    ui->setupUi(this);

//    QPalette pal;
//    pal.setBrush(this->backgroundRole(), QBrush(QImage(":/good_images/background1.png")));
//    this->setPalette(pal);
//    this->setAutoFillBackground(true);

//    this->setWindowOpacity(0.5);
//    this->setAttribute(Qt::WA_TranslucentBackground, true);
//    this->setWindowOpacity(0.8);

    //setAttribute(Qt::WA_TranslucentBackground, true);

}

Mouse_Dialog::~Mouse_Dialog()
{
    delete ui;
}

bool Mouse_Dialog::event(QEvent *e)
{
    if(e->type() == QEvent::Gesture){
        return gestureEvent(static_cast<QGestureEvent *>(e));
    }
    return QWidget::event(e);
}

void Mouse_Dialog::paintEvent(QPaintEvent *event)   //此处为设置背景
{

    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/good_images/background1.png"));

}

void Mouse_Dialog::setAddr(QString addrip, int addrport)
{
    ip = addrip;
    port = addrport;

    isStarted = false;
    udpSocket = new QUdpSocket(this);
    address.setAddress(ip);


    //----------------------------触摸设置------------------------------
    this->grabGesture(Qt::PanGesture);  //使能Pan，调用这个函数pan(捏)滑动手势被允许，这将使Udpserver作为QGestureEvents的目标。
    this->grabGesture(Qt::PinchGesture);//调用这个函数pinch(捏)手势被允许，这将使Udpserver作为QGestureEvents的目标。
    this->grabGesture(Qt::SwipeGesture);
    this->grabGesture(Qt::TapAndHoldGesture);   //点拖
    this->grabGesture(Qt::TapGesture);  //点击
        //qDebug() << "-----------------";

    //----------------------------重力传感器------------------------------
    this->m_sensor = new QAccelerometer(this);
    this->m_sensor->addFilter(this);
    connect(this->m_sensor, SIGNAL(readingChanged()), this, SLOT(checkReading()));
    this->m_sensor->start();
    qDebug() << "availableDataRates = " << this->m_sensor->availableDataRates();
    qDebug() << "bufferSize = " << this->m_sensor->bufferSize();
    qDebug() << "outputRange = " << this->m_sensor->outputRange();

}


void Mouse_Dialog::sendPos(void)   //send offset
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
    //address.setAddress("192.168.137.6");    //发送者要把数据发送到的IP地址
    this->udpSocket->writeDatagram(strData, address, port);
}




/******************************以下为手势操作***********************************/
void Mouse_Dialog::swipeTriggered(QSwipeGesture *gesture)
{

}

void Mouse_Dialog::panTriggered(QPanGesture *gesture)
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

void Mouse_Dialog::pinchTriggered(QPinchGesture *gesture)
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

void Mouse_Dialog::tapTriggered(QTapGesture *gesture)
{
    //this->on_Button_Left_clicked();
}

void Mouse_Dialog::tap_hold_Triggered(QTapAndHoldGesture *gesture)
{

}

bool Mouse_Dialog::gestureEvent(QGestureEvent *e)
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
















void Mouse_Dialog::on_power_button_clicked()
{
    //qDebug() << "on_power_release";
    QByteArray arr;
    arr.resize(3);
    arr[0] = STX;
    arr[1] = POWER_OFF;
    arr[2] = ETX;
    this->udpSocket->writeDatagram(arr, address, this->port);
}

void Mouse_Dialog::on_advance_Button_clicked()
{
    QByteArray arr;
    arr.resize(3);
    arr[0] = STX;
    arr[1] = LCLICK;
    arr[2] = ETX;

    //this->udpSocket->writeDatagram(arr, arr.count(), QHostAddress::Broadcast, this->port);
    //QHostAddress address;
    //address.setAddress("192.168.137.6");    //发送者要把数据发送到的IP地址
    this->udpSocket->writeDatagram(arr, address, this->port);

}

void Mouse_Dialog::on_advance_Button_2_clicked()
{
    QByteArray arr;
    arr.resize(3);
    arr[0] = STX;
    arr[1] = RCLICK;
    arr[2] = ETX;

    //this->udpSocket->writeDatagram(arr, arr.count(), QHostAddress::Broadcast, this->port);

    //QHostAddress address;
    //address.setAddress("192.168.137.6");    //发送者要把数据发送到的IP地址
    this->udpSocket->writeDatagram(arr, address, this->port);

}

bool Mouse_Dialog::filter(QAccelerometerReading *reading)
{

}

void Mouse_Dialog::checkReading()
{
    qreal x = this->m_sensor->reading()->x();
    qreal y = this->m_sensor->reading()->y();
    qreal z = this->m_sensor->reading()->z();

    ui->lbl_x->setText("x: " + QString::number(x));
    ui->lbl_y->setText("y: " + QString::number(y));
    ui->lbl_z->setText("z: " + QString::number(z));

    if(fabs(this->x - x) > 1 || fabs(this->y - y) > 1){
        this->x = 0 - x * 3;    //扩大到两倍
        this->y = y * 3;
        this->sendPos();
    }
}

