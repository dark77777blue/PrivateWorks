#ifndef UDPSERVER_H
#define UDPSERVER_H

//#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QUdpSocket>
#include <QTimer>
#include <QWidget>
#include <QString>
#include <QPanGesture>  //移动手势
//#include <QGraphicsWebView>
#include <QGestureEvent>
#include <QEvent>

#include <QAccelerometerFilter>
#include <QAccelerometerReading>
#include <QAccelerometer>


/********** 以下为协议命令 ************/
#define     STX         0x02    //报文开始标志

#define     POS         0x10    //光标位置
#define     LCLICK      0x14    //单击
#define     RCLICK      0x16    //右击
#define     DCLICK      0x18    //双击
//------------------------------------------------------------------------
#define     LPRESS      0x21    //左键按下
#define     LRELEASE    0x22    //左键释放
#define     RPRESS      0x23    //右键按下
#define     RRELEASE    0x24    //右键释放

#define     POWER_OFF   0x30    //关机

#define     ETX         0x03    //数据终止符
/*
    光标位置报文： STX POS x:y ETX     //长度不固定
    单击报文：    STX LCLICK ETX      //3Byte
    右击报文：    STX RCLICK ETX      //3Byte
*/

namespace Ui {
class Widget;
}

class Udpserver : public QWidget, public QAccelerometerFilter
{
    Q_OBJECT
public:
    Udpserver(QString addr, QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~Udpserver();

private:
    bool gestureEvent(QGestureEvent *e);
    void swipeTriggered(QSwipeGesture *gesture);
    void panTriggered(QPanGesture *gesture);
    void pinchTriggered(QPinchGesture *gesture);
    void tapTriggered(QTapGesture *gesture);
    void tap_hold_Triggered(QTapAndHoldGesture *gesture);

private:
    bool filter(QAccelerometerReading *reading);    //传感器数据变化时将自动调用该虚函数

private:
    QAccelerometer *m_sensor;   //传感器

    Ui::Widget *ui;
    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QHostAddress address;
    //QTimer *timer;

    int x, y;

    void sendPos(void);

public slots:
    //void timeout();

private slots:
    void on_Button_Left_clicked();
    void on_Button_Right_clicked();

    void on_power_release();
    void on_left_release(); //gougou
    void on_right_release();



    void checkReading();

protected:
    bool event(QEvent *e);
};


#endif // UDPSERVER_H
