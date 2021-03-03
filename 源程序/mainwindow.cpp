#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "applywindow.h"
#include "filewindow.h"
#include <QApplication>
#include <QtDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowIcon(QIcon(":/resouce/icon.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn_exit_clicked()
{
    QApplication *app;
    app->quit();
}

void MainWindow::on_Btn_login_clicked()
{
    applywindow *apply = new applywindow(this);
    apply->setWindowTitle("申请账号");
    apply->show();
    this->hide();
}

void MainWindow::on_Btn_appl_clicked()
{
    QSqlQuery query1,query2,query3,query4;
    QString id1 = this->ui->txt_userid->text();
    QString psd = this->ui->txt_psd->text();
    QString str=QString("select * from usetab where id='%1' and psw='%2'").arg(id1).arg(psd);
    QString select_id=QString("select id from usetab where id='%1'").arg(id1);
    QString select_psd=QString("select psw from usetab where id='%1'").arg(id1);
    QString select_name=QString("select username from usetab where id='%1'").arg(id1);
    if(id1==""||psd==""){
        QMessageBox::critical(this,"提示","请输入账号或密码!");
        return;
    }
    query1.exec(select_id);
    if(query1.first()==NULL){
        QMessageBox::critical(this,"提示","用户不存在！");
        return;
    }
    query1.next();
    query3.exec(select_psd);
    query3.first();
    QString pswdet;
    pswdet=query3.value(0).toString();
    if(pswdet!=psd){
        QMessageBox::critical(this,"提示","密码错误！");
        return;
    }
    query2.exec(str);
    if(query2.first()){
        QMessageBox::information(this,"提示","登录成功！");
        this->hide();
        filewindow *mainw = new filewindow();
        query4.exec(select_name);
        query4.next();
        this->myname=query4.value(0).toString();
        connect(this,SIGNAL(sendname(QString)),mainw,SLOT(getname(QString)));
        qDebug()<<this->myname;
        qDebug()<<myname;
        emit sendname(myname);
        mainw->setWindowTitle("汽车预约管理系统");
        mainw->show();
    }
    else{
        QMessageBox::critical(this,"提示","登陆失败！");
        return;
    }
}


