#ifndef APPLYWINDOW_H
#define APPLYWINDOW_H

#include <QDialog>

namespace Ui {
class applywindow;
}

class applywindow : public QDialog
{
    Q_OBJECT

public:
    explicit applywindow(QWidget *parent = nullptr);
    ~applywindow();

private slots:
    void on_Btn_back_clicked();

    void on_Btn_conf_clicked();

private:
    Ui::applywindow *ui;
};

#endif // APPLYWINDOW_H
