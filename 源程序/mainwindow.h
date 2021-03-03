#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <filewindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString myname;

signals:
    void sendname(QString data);

private slots:
    void on_Btn_exit_clicked();

    void on_Btn_login_clicked();

    void on_Btn_appl_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
