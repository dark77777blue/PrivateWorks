#ifndef SETUP_H
#define SETUP_H
#include <QDialog>

namespace Ui {
class SetUp;
}

class SetUp : public QDialog
{
    Q_OBJECT
public:
    SetUp(QWidget *parent = 0);
    ~SetUp();

private:

    Ui::SetUp *ui;
    int port;

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};





#endif // SETUP_H
