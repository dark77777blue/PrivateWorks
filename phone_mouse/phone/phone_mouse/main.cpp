#include <QApplication>
#include "SetUp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SetUp w;
    w.show();

    return a.exec();
}
