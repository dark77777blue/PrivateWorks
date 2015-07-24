#ifndef BUTTON_H
#define BUTTON_H

//#include <QtDesigner/QDesignerExportWidget>
#include <QWidget>
#include <QBitmap>
#include <QPixmap>
#include <QPoint>

class Advance_Button : public QWidget
{
    Q_OBJECT            //此处使用RESET设置默认属性值，在Qt Designer中还是不起作用，在Advance_Button构造函数中设置初始值则管用
    Q_PROPERTY(QPixmap  Picture READ read_ButtonPicture WRITE setButtonPicture)   //以下函数为设置图片的函数
    Q_PROPERTY(bool  ClickEnable READ read_isclick WRITE set_isclick)
    Q_PROPERTY(bool  DragEnable READ read_isdrag WRITE set_isdrag)

public:
    QPixmap read_ButtonPicture() const {return buttonPicture;}
    bool read_isclick() const {return isClick;}
    bool read_isdrag() const {return isDrag;}

    void setButtonPicture(const QPixmap &pic);
    void set_isclick(bool click) {isClick = click; if(!click){isDrag = false;} }
    void set_isdrag(bool drag) {isDrag = drag;}


public:
    Advance_Button(QWidget *parent);
    ~Advance_Button();

    void set_X_Y_width_height(int x, int y, int width, int height);

signals:    //custom signals
    void press_pos(QPoint pos);
    void release_pos(QPoint pos);
    void click();

protected:
    //void mouseDoubleClickEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void resizeEvent(QResizeEvent *e);

    void paintEvent(QPaintEvent *e);

private:
    QPixmap buttonPicture;
    bool isDrag;    //true:能够被移动,false:不能移动
    bool isClick;   //true:能触被点击；


    QPixmap pressPicture;
    bool    press_flag; //是否按下
//    QPixmap *releasePicutre;


    QPoint  *dragPos;

};




#endif // BUTTON_H




















