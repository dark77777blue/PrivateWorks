#ifndef REMOTE_DIALOG_H
#define REMOTE_DIALOG_H

#include <QDialog>

namespace Ui {
class Remote_Dialog;
}

class Remote_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Remote_Dialog(QWidget *parent = 0);
    ~Remote_Dialog();

private:
    Ui::Remote_Dialog *ui;
};

#endif // REMOTE_DIALOG_H
