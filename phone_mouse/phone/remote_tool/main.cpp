#include <QApplication>
#include <QDesktopWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize size = a.desktop()->screenGeometry().size();
    MainWindow w;
    w.resize(size);

    //主窗体透明，子窗体不透明
    //w.setAttribute(Qt::WA_TranslucentBackground, true);
    //w.setWindowOpacity(0.6);

    w.show();

    return a.exec();
}
