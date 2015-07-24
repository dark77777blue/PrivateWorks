#ifndef BUTTON_H
#define BUTTON_H

//#include <QtDesigner/QDesignerExportWidget>
#include <QPushButton>
#include <QBitmap>
#include <QPixmap>
#include <QPoint>

class Advance_Button : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QPixmap  buttonPicture READ read_ButtonPicture WRITE setButtonPicture)   //以下三个函数为设置图片的函数
    Q_PROPERTY(QPixmap  pressPicture READ read_PressPicture WRITE setPressPicture)
    Q_PROPERTY(QPixmap  releasePicutre READ read_ReleasePicture WRITE setReleasePicture)

    Q_PROPERTY(bool  isdrag READ read_isdrag WRITE set_isdrag)


public:
    QPixmap * read_ButtonPicture() const {return buttonPicture;}
    QPixmap * read_PressPicture() const {return pressPicture;}
    QPixmap * read_ReleasePicture() const {return releasePicutre;}
    bool read_isdrag() const {return isdrag;}
    void setButtonPicture(QPixmap pic);
    void setPressPicture(QPixmap pic);
    void setReleasePicture(QPixmap pic);
    void set_isdrag(bool drag) {isdrag = drag;}


public:
    Advance_Button(QWidget *parent);
    ~Advance_Button();

    void set_X_Y_width_height(int x, int y, int width, int height);

signals:    //custom signals
    void press(QPoint pos);
    void release(QPoint pos);

protected:
    //void mouseDoubleClickEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    //void paintEvent(QPaintEvent *e);

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicutre;

    bool isdrag;    //true:能够被移动,false:不能移动

    QPoint  *dragPos;

};




#endif // BUTTON_H




















