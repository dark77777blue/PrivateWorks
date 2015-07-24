#include "advance_button.h"

#include <QPainter>
#include <QMouseEvent>

Advance_Button::Advance_Button(QWidget *parent) : QWidget(parent)
{
    dragPos = new QPoint;
    press_flag = false; //初始设为未按下

    //this->setWindowFlags(Qt::FramelessWindowHint);

//    this->setAttribute(Qt::WA_DeleteOnClose);
//    this->setAttribute(Qt::WA_TranslucentBackground);

    //this->setFlat(true);    //边框
    QPixmap map(this->size());
    map.fill(Qt::red);
    buttonPicture = map; //此处初始化在Qt Designer中能起作用
    update();

    isDrag = false; //此处初始化在Qt Designer中能起作用
    isClick = true; //此处初始化在Qt Designer中能起作用
    this->setWindowFlags(Qt::FramelessWindowHint);  //设置窗体无边框
    this->setAttribute(Qt::WA_TranslucentBackground);   //设置背景透明
}

Advance_Button::~Advance_Button()
{
//    delete buttonPicture;
//    delete pressPicture;
//    delete releasePicutre;
    delete dragPos;
}

void Advance_Button::setButtonPicture(const QPixmap &pic)
{
    buttonPicture = pic.scaled(this->size());  //参照按钮的大小设置图片的大小
    pressPicture = pic.scaled(this->size()*0.9);
//    this->setIcon(QIcon(*buttonPicture));
//    this->setIconSize(this->size());
    this->setMask(buttonPicture.mask());//------------隐藏透明部分和禁止点击透明部分----------------
//    update();
//    updateGeometry();
}

//void Advance_Button::setPressPicture(QPixmap pic)
//{
//    *pressPicture = pic.scaled(this->size());  //参照按钮的大小设置图片的大小;
//}

//void Advance_Button::setReleasePicture(QPixmap pic)
//{
//    *releasePicutre = pic.scaled(this->size());  //参照按钮的大小设置图片的大小;
//}

void Advance_Button::set_X_Y_width_height(int x, int y, int width, int height)
{
//    this->setIconSize(QSize(width, height));
//    this->setGeometry(x, y , width, height);
}

//-------------------------------------------------------------------------------
//void Button::mouseDoubleClickEvent(QMouseEvent *e){}    //暂时不实现
void Advance_Button::mouseMoveEvent(QMouseEvent *e)
{
    if(isDrag == false){    //禁止移动
        return ;
    }

    if(e->buttons() & Qt::LeftButton){
        move(e->globalPos() - *dragPos);
        e->accept();
    }
}

void Advance_Button::mousePressEvent(QMouseEvent *e)
{
    //this->setIcon(QIcon(*pressPicture));
    //this->setIconSize(this->size());
    //this->setMask(pressPicture->mask());//------------
    if(isClick == false){    //禁止点击
        return ;
    }

    if(e->button() == Qt::LeftButton){
        *dragPos = e->globalPos() - frameGeometry().topLeft();
        e->accept();
    }

    emit press_pos(e->globalPos());

    press_flag = true;
    repaint();
}


void Advance_Button::mouseReleaseEvent(QMouseEvent *e)
{
//    this->setIcon(QIcon(*releasePicutre));
//    this->setIconSize(this->size());
    //this->setMask(releasePicutre->mask());//------------
    //emit clicked();
    emit release_pos(e->globalPos());
    emit click();

    press_flag = false;
    repaint();

}

void Advance_Button::resizeEvent(QResizeEvent *e)   //必须重载此函数，否则无法在布局中使用
{
    //this->setIconSize(e->size());
    this->clearMask();
    buttonPicture = buttonPicture.scaled(e->size());
    pressPicture = buttonPicture.scaled(e->size()*0.9);
    //QWidget::resizeEvent(e);
    repaint();
    this->setMask(buttonPicture.mask());//------------隐藏透明部分和禁止点击透明部分----------------
    //e->accept();

}


void Advance_Button::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(press_flag){   //按下
        painter.fillRect(0, 0,pressPicture.width() , pressPicture.height(), pressPicture);
    }else{
        painter.fillRect(0, 0, buttonPicture.width() , buttonPicture.height(), buttonPicture);
    }
}




















