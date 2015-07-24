#include "advance_button.h"

#include <QPainter>
#include <QMouseEvent>

Advance_Button::Advance_Button(QWidget *parent) : QPushButton(parent)
{
    dragPos = new QPoint;

    //-----------------------以下五个值由设计师设定---------------------------
    buttonPicture = new QPixmap;//(":/images/yoda.png");  //设置初始化图标，方便设计师定位
    pressPicture = new QPixmap;//(":/images/yoda1.png");
    releasePicutre = new QPixmap;//(":/images/yoda.png");


    //this->setWindowFlags(Qt::FramelessWindowHint);

    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setFlat(true);    //边框

}

Advance_Button::~Advance_Button()
{
    delete buttonPicture;
    delete pressPicture;
    delete releasePicutre;
    delete dragPos;
}

void Advance_Button::setButtonPicture(QPixmap pic)
{
    *buttonPicture = pic.scaled(this->size());  //参照按钮的大小设置图片的大小

    this->setIcon(QIcon(*buttonPicture));
    this->setIconSize(this->size());
    this->setMask(buttonPicture->mask());//------------隐藏透明部分和禁止点击透明部分----------------
}

void Advance_Button::setPressPicture(QPixmap pic)
{
    *pressPicture = pic.scaled(this->size());  //参照按钮的大小设置图片的大小;
}

void Advance_Button::setReleasePicture(QPixmap pic)
{
    *releasePicutre = pic.scaled(this->size());  //参照按钮的大小设置图片的大小;
}

void Advance_Button::set_X_Y_width_height(int x, int y, int width, int height)
{
    this->setIconSize(QSize(width, height));
    this->setGeometry(x, y , width, height);
}

//-------------------------------------------------------------------------------
//void Button::mouseDoubleClickEvent(QMouseEvent *e){}    //暂时不实现
void Advance_Button::mouseMoveEvent(QMouseEvent *e)
{
    if(isdrag == false){    //禁止移动
        return ;
    }

    if(e->buttons() & Qt::LeftButton){
        move(e->globalPos() - *dragPos);
        e->accept();
    }
}

void Advance_Button::mousePressEvent(QMouseEvent *e)
{
    this->setIcon(QIcon(*pressPicture));
    this->setIconSize(this->size());
    this->setMask(pressPicture->mask());//------------

    if(e->button() == Qt::LeftButton){
        *dragPos = e->globalPos() - frameGeometry().topLeft();
        e->accept();
    }

    emit press(e->globalPos());
}


void Advance_Button::mouseReleaseEvent(QMouseEvent *e)
{
    this->setIcon(QIcon(*releasePicutre));
    this->setIconSize(this->size());
    this->setMask(releasePicutre->mask());//------------
    //emit clicked();
    emit release(e->globalPos());
}

/*
void Advance_Button::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.fillRect(0, 0, buttonPicture->width(), buttonPicture->height(), *buttonPicture);
}
*/




















