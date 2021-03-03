#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QDialog>

namespace Ui {
class filewindow;
}

class filewindow : public QDialog
{
    Q_OBJECT

public:
    QString name;
    QString id;

    QString type1;
    QString type2;
    QString type3;
    QString type4;
    QString type5;
    QString type6;
    QString type7;
    QString type8;

    void InitTableWidget2();
    void InitTableWidget4();
    void removeCombo();
    void updatebuy();
    void updatemend();
    void updatecmt();
    explicit filewindow(QWidget *parent = nullptr);
    ~filewindow();

public slots:
    void getname(QString data);

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::filewindow *ui;
};

#endif // FILEWINDOW_H
