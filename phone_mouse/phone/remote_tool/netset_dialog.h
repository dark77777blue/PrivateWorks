#ifndef NETSET_DIALOG_H
#define NETSET_DIALOG_H

#include <QDialog>

namespace Ui {
class NetSet_Dialog;
}

class NetSet_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit NetSet_Dialog(QWidget *parent = 0);
    ~NetSet_Dialog();

private slots:
    void on_saveBtn_clicked();

private:
    Ui::NetSet_Dialog *ui;
};

#endif // NETSET_DIALOG_H
