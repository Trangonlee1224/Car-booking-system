#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QMessageBox>
bool OpenDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); //数据库驱动类型为SQL Server
    QString dsn = QString::fromLocal8Bit("mydatabase");
    db.setHostName("127.0.0.1");        //选择本地主机，127.0.0.1
    db.setDatabaseName(dsn);
    db.setUserName("myuser");            //登录用户
    db.setPassword("123456");                    //密码
    if(!db.open())                                  //打开数据库
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
        return false ;                 //打开失败
    }
    return true;
}
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    if(!OpenDatabase())
        return 1;

    //w.setWindowIcon(QIcon(":\\resouce\\icon.ico"));
    w.setWindowTitle("用户登录");
    w.show();
    return a.exec();
}
