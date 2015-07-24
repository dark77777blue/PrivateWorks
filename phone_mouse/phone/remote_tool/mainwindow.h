#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //void paintEvent(QPaintEvent *event);
private slots:
    void on_mouse_action_triggered();

    void on_sys_action_triggered();

    void on_remoute_action_triggered();

    void on_net_action_triggered();

    void on_other_action_triggered();

private:
    Ui::MainWindow *ui;

public:
    QString addr_ip;
    int     addr_port;
};

#endif // MAINWINDOW_H
