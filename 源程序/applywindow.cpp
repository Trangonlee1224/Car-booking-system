#include "applywindow.h"
#include "ui_applywindow.h"
#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

applywindow::applywindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::applywindow)
{
    ui->setupUi(this);
}

applywindow::~applywindow()
{
    delete ui;
}

void applywindow::on_Btn_back_clicked()
{
    this->hide();
    MainWindow *mainw = new MainWindow(this);
    mainw->setWindowTitle("用户登录");
    mainw->show();
}

void applywindow::on_Btn_conf_clicked()
{
    QSqlQuery query;
    QString s;
    QString id = this->ui->txt_ID->text();
    QString name = this->ui->txt_name->text();
    QString psw = this->ui->txt_psd->text();
    QString psw2 = this->ui->txt_cfpsd->text();
    QString tel = this->ui->txt_tel->text();
    s=QString("insert into usetab values('%1','%2','%3','%4','%5')").arg(id).arg(name).arg(psw).arg(psw2).arg(tel);
    if(id.length()<6){
        QMessageBox::critical(this,"提示","账号不能小于6位！");
        return;
    }
    if (psw.length()<6) {
        QMessageBox::critical(this,"提示","密码不能小于8位！");
        return;
    }
    if(psw != psw2){
        QMessageBox::critical(this,"提示","两次输入密码不一致！");
        return;
    }
    if(query.exec(s)){
        QMessageBox::information(this,"通知","注册成功！");
        this->hide();
        MainWindow *mainw = new MainWindow(this);
        mainw->show();
    }
    else {
        QMessageBox::critical(this,"通知","注册失败");
    }
}
