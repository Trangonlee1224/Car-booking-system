#include "ui_filewindow.h"
#include "mainwindow.h"
#include "applywindow.h"
#include "filewindow.h"
#include "code.h"
#include "code2.h"
#include <QApplication>
#include <QtDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>


filewindow::filewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filewindow)
{
    ui->setupUi(this);
    //ui->label_2->setText(this->name);

    this->type1="大众";
    this->type2="起亚";
    this->type3="现代";
    this->type4="雪佛兰";
    this->type5="丰田";
    this->type6="宝马";
    this->type7="福特";
    this->type8="吉利";
    ui->comboBox->addItem(type1);
    ui->comboBox->addItem(type2);
    ui->comboBox->addItem(type3);
    ui->comboBox->addItem(type4);
    ui->comboBox->addItem(type5);
    ui->comboBox->addItem(type6);
    ui->comboBox->addItem(type7);
    ui->comboBox->addItem(type8);
    ui->comboBox->setCurrentIndex(-1);

    ui->tableWidget->setColumnCount(6);
    //ui->tableWidget->setWindowTitle("车辆信息");
    QStringList mHeader;
    mHeader<<QString("车型")<<QString("油耗")<<QString("排量")<<QString("所属品牌")<<QString("价格")<<QString("余量");
    ui->tableWidget->setHorizontalHeaderLabels(mHeader);//添加横向表头
    ui->tableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
    ui->tableWidget->horizontalHeader()->setVisible(true);//横向表头可视化

    ui->tableWidget_2->setColumnCount(4);
    QStringList mHeader2;
    mHeader2<<QString("4S店编号")<<QString("所在地")<<QString("品牌")<<QString("电话");
    ui->tableWidget_2->setHorizontalHeaderLabels(mHeader2);//添加横向表头
    ui->tableWidget_2->verticalHeader()->setVisible(true);//纵向表头可视化
    ui->tableWidget_2->horizontalHeader()->setVisible(true);//横向表头可视化

    ui->tableWidget_3->setColumnCount(4);
    QStringList mHeader3;
    mHeader3<<QString("预约/购买")<<QString("预约/购买时间")<<QString("车型")<<QString("用户");
    ui->tableWidget_3->setHorizontalHeaderLabels(mHeader3);//添加横向表头
    ui->tableWidget_3->verticalHeader()->setVisible(true);//纵向表头可视化
    ui->tableWidget_3->horizontalHeader()->setVisible(true);//横向表头可视化

    ui->tableWidget_4->setColumnCount(4);
    QStringList mHeader4;
    mHeader4<<QString("维修商编号")<<QString("所在地")<<QString("品牌")<<QString("电话");
    ui->tableWidget_4->setHorizontalHeaderLabels(mHeader4);//添加横向表头
    ui->tableWidget_4->verticalHeader()->setVisible(true);//纵向表头可视化+
    ui->tableWidget_4->horizontalHeader()->setVisible(true);//横向表头可视化

    ui->tableWidget_5->setColumnCount(4);
    QStringList mHeader5;
    mHeader5<<QString("维修/保养时间")<<QString("车型")<<QString("用户")<<QString("操作");
    ui->tableWidget_5->setHorizontalHeaderLabels(mHeader5);//添加横向表头
    ui->tableWidget_5->verticalHeader()->setVisible(true);//纵向表头可视化
    ui->tableWidget_5->horizontalHeader()->setVisible(true);//横向表头可视化

    ui->tableWidget_6->setColumnCount(3);
    QStringList mHeader6;
    mHeader6<<QString("用户")<<QString("时间")<<QString("内容");
    ui->tableWidget_6->setHorizontalHeaderLabels(mHeader6);//添加横向表头
    ui->tableWidget_6->verticalHeader()->setVisible(true);//纵向表头可视化
    ui->tableWidget_6->horizontalHeader()->setVisible(true);//横向表头可视化

    this->InitTableWidget2();
    this->InitTableWidget4();
    this->updatebuy();
    this->updatemend();
    this->updatecmt();
}


filewindow::~filewindow()
{
    delete ui;
}

void filewindow::on_comboBox_currentIndexChanged(int index)
{
    ui->tableWidget->clearContents();
    int rowct=ui->tableWidget->rowCount();
    while(rowct--)
        ui->tableWidget->removeRow(rowct);
    QSqlQuery query;
    QString test=ui->comboBox->currentText();
    index=ui->comboBox->currentIndex();
    test = QString("Select * from cars where company = '%1'").arg(test);
    if(query.exec(test)){
        while(query.next()){
            QString type=query.value(0).toString();
            QString fuel=query.value(1).toString();
            QString trans=query.value(2).toString();
            QString company=query.value(3).toString();
            QString cost=query.value(4).toString();
            QString num=query.value(5).toString();
            int rowcount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowcount);

            ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(type));
            ui->tableWidget->setItem(rowcount,1,new QTableWidgetItem(fuel));
            ui->tableWidget->setItem(rowcount,2,new QTableWidgetItem(trans));
            ui->tableWidget->setItem(rowcount,3,new QTableWidgetItem(company));
            ui->tableWidget->setItem(rowcount,4,new QTableWidgetItem(cost));
            ui->tableWidget->setItem(rowcount,5,new QTableWidgetItem(num));
        }
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if(index==0){
        ui->comboBox_2->addItem("途锐SUV");
        ui->comboBox_2->addItem("甲壳虫");
        ui->comboBox_2->addItem("迈特威MPV");
        ui->comboBox_2->addItem("Golf");
    }
    else if(index==1){
        removeCombo();
        ui->comboBox_2->addItem("东风K3");
        ui->comboBox_2->addItem("起亚KX5");
    }
    else if(index==2){
        removeCombo();
        ui->comboBox_2->addItem("瑞纳");
        ui->comboBox_2->addItem("菲斯特");
        ui->comboBox_2->addItem("胜达");
    }
    else if(index==3){
        removeCombo();
        ui->comboBox_2->addItem("科鲁兹");
        ui->comboBox_2->addItem("探界者");
        ui->comboBox_2->addItem("沃兰多");
    }
    else if(index==4){
        removeCombo();
        ui->comboBox_2->addItem("普拉多");
        ui->comboBox_2->addItem("RAV4荣放");
        ui->comboBox_2->addItem("亚洲龙");
        ui->comboBox_2->addItem("科罗拉");
    }
    else if(index==5){
        removeCombo();
        ui->comboBox_2->addItem("宝马2系敞篷");
        ui->comboBox_2->addItem("宝马8系敞篷");
        ui->comboBox_2->addItem("宝马i8");
        ui->comboBox_2->addItem("宝马X6");
    }
    else if(index==6){
        removeCombo();
        ui->comboBox_2->addItem("金牛座");
        ui->comboBox_2->addItem("锐界");
        ui->comboBox_2->addItem("翼虎");
        ui->comboBox_2->addItem("福克斯Active");
    }
    else if(index==7){
        removeCombo();
        ui->comboBox_2->addItem("缤越");
        ui->comboBox_2->addItem("帝豪GS");
    }
    else {
        removeCombo();
    }
}

void filewindow::InitTableWidget2(){
    QSqlQuery query2;
    QString test2;
    test2=QString("select * from agent");
    if(query2.exec(test2)){
        while(query2.next()){
            QString id=query2.value(0).toString();
            QString city=query2.value(1).toString();
            QString company=query2.value(2).toString();
            QString tel=query2.value(3).toString();
            int rowcount = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(rowcount);

            ui->tableWidget_2->setItem(rowcount,0,new QTableWidgetItem(id));
            ui->tableWidget_2->setItem(rowcount,1,new QTableWidgetItem(city));
            ui->tableWidget_2->setItem(rowcount,2,new QTableWidgetItem(company));
            ui->tableWidget_2->setItem(rowcount,3,new QTableWidgetItem(tel));
        }
    }
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void filewindow::InitTableWidget4(){
    QSqlQuery query4;
    QString test4;
    test4=QString("select * from maintance");
    if(query4.exec(test4)){
        while(query4.next()){
            QString id=query4.value(0).toString();
            QString city=query4.value(1).toString();
            QString company=query4.value(2).toString();
            QString tel=query4.value(3).toString();
            int rowcount = ui->tableWidget_4->rowCount();
            ui->tableWidget_4->insertRow(rowcount);

            ui->tableWidget_4->setItem(rowcount,0,new QTableWidgetItem(id));
            ui->tableWidget_4->setItem(rowcount,1,new QTableWidgetItem(city));
            ui->tableWidget_4->setItem(rowcount,2,new QTableWidgetItem(company));
            ui->tableWidget_4->setItem(rowcount,3,new QTableWidgetItem(tel));
        }
    }
    ui->tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void filewindow::on_pushButton_clicked()
{
    ui->tableWidget_2->clearContents();
    int rowct=ui->tableWidget_2->rowCount();
    while(rowct--)
        ui->tableWidget_2->removeRow(rowct);
    QSqlQuery query;
    QString cars, test1;
    cars=ui->lineEdit->text();
    test1 = QString("select * from agent where company='%1'").arg(cars);
    if(query.exec(test1)){
        while(query.next()){
            QString id=query.value(0).toString();
            QString city=query.value(1).toString();
            QString company=query.value(2).toString();
            QString tel=query.value(3).toString();
            int rowcount = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(rowcount);

            ui->tableWidget_2->setItem(rowcount,0,new QTableWidgetItem(id));
            ui->tableWidget_2->setItem(rowcount,1,new QTableWidgetItem(city));
            ui->tableWidget_2->setItem(rowcount,2,new QTableWidgetItem(company));
            ui->tableWidget_2->setItem(rowcount,3,new QTableWidgetItem(tel));
        }
    }

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QList<QTableWidgetItem*> items = ui->tableWidget->selectedItems();
    int count = items.count();
    for(int i = 0; i < count; i++)
    {
        int row = ui->tableWidget->row(items.at(i));
        QTableWidgetItem *item = items.at(i);
        QString name = item->text(); //获取内容
        qDebug()<<item;
    }
}

void filewindow::on_pushButton_5_clicked()
{
    ui->tableWidget_2->clearContents();
    int rowct=ui->tableWidget_2->rowCount();
    while(rowct--)
        ui->tableWidget_2->removeRow(rowct);
    this->InitTableWidget2();
}

void filewindow::on_pushButton_2_clicked()
{
    ui->tableWidget_2->clearContents();
    int rowct=ui->tableWidget_2->rowCount();
    while(rowct--)
        ui->tableWidget_2->removeRow(rowct);
    QSqlQuery query;
    QString city, test1;
    city=ui->lineEdit_2->text();
    test1 = QString("select * from agent where city='%1'").arg(city);
    if(query.exec(test1)){
        while(query.next()){
            QString id=query.value(0).toString();
            QString city=query.value(1).toString();
            QString company=query.value(2).toString();
            QString tel=query.value(3).toString();
            int rowcount = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(rowcount);

            ui->tableWidget_2->setItem(rowcount,0,new QTableWidgetItem(id));
            ui->tableWidget_2->setItem(rowcount,1,new QTableWidgetItem(city));
            ui->tableWidget_2->setItem(rowcount,2,new QTableWidgetItem(company));
            ui->tableWidget_2->setItem(rowcount,3,new QTableWidgetItem(tel));
        }
    }

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void filewindow::on_pushButton_6_clicked()
{
    ui->tableWidget_2->clearContents();
    int rowct=ui->tableWidget_2->rowCount();
    while(rowct--)
        ui->tableWidget_2->removeRow(rowct);
    QSqlQuery query;
    QString cars, city, test1;
    cars=ui->lineEdit->text();
    city=ui->lineEdit_2->text();
    test1 = QString("select * from agent where company='%1' and city='%2'").arg(cars).arg(city);
    if(query.exec(test1)){
        while(query.next()){
            QString id=query.value(0).toString();
            QString city=query.value(1).toString();
            QString company=query.value(2).toString();
            QString tel=query.value(3).toString();
            int rowcount = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(rowcount);

            ui->tableWidget_2->setItem(rowcount,0,new QTableWidgetItem(id));
            ui->tableWidget_2->setItem(rowcount,1,new QTableWidgetItem(city));
            ui->tableWidget_2->setItem(rowcount,2,new QTableWidgetItem(company));
            ui->tableWidget_2->setItem(rowcount,3,new QTableWidgetItem(tel));
        }
    }

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void filewindow::on_pushButton_4_clicked()
{
    ui->tableWidget_4->clearContents();
    int rowct=ui->tableWidget_4->rowCount();
    while(rowct--)
        ui->tableWidget_4->removeRow(rowct);
    QSqlQuery query;
    QString cars, test1;
    cars=ui->lineEdit_4->text();
    test1 = QString("select * from maintance where company='%1'").arg(cars);
    if(query.exec(test1)){
        while(query.next()){
            QString id=query.value(0).toString();
            QString city=query.value(1).toString();
            QString company=query.value(2).toString();
            QString tel=query.value(3).toString();
            int rowcount = ui->tableWidget_4->rowCount();
            ui->tableWidget_4->insertRow(rowcount);

            ui->tableWidget_4->setItem(rowcount,0,new QTableWidgetItem(id));
            ui->tableWidget_4->setItem(rowcount,1,new QTableWidgetItem(city));
            ui->tableWidget_4->setItem(rowcount,2,new QTableWidgetItem(company));
            ui->tableWidget_4->setItem(rowcount,3,new QTableWidgetItem(tel));
        }
    }

    ui->tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void filewindow::on_pushButton_3_clicked()
{
    ui->tableWidget_4->clearContents();
    int rowct=ui->tableWidget_4->rowCount();
    while(rowct--)
        ui->tableWidget_4->removeRow(rowct);
    QSqlQuery query;
    QString city, test1;
    city=ui->lineEdit_3->text();
    test1 = QString("select * from maintance where city='%1'").arg(city);
    if(query.exec(test1)){
        while(query.next()){
            QString id=query.value(0).toString();
            QString city=query.value(1).toString();
            QString company=query.value(2).toString();
            QString tel=query.value(3).toString();
            int rowcount = ui->tableWidget_4->rowCount();
            ui->tableWidget_4->insertRow(rowcount);

            ui->tableWidget_4->setItem(rowcount,0,new QTableWidgetItem(id));
            ui->tableWidget_4->setItem(rowcount,1,new QTableWidgetItem(city));
            ui->tableWidget_4->setItem(rowcount,2,new QTableWidgetItem(company));
            ui->tableWidget_4->setItem(rowcount,3,new QTableWidgetItem(tel));
        }
    }

    ui->tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void filewindow::on_pushButton_7_clicked()
{
    ui->tableWidget_4->clearContents();
    int rowct=ui->tableWidget_4->rowCount();
    while(rowct--)
        ui->tableWidget_4->removeRow(rowct);
    QSqlQuery query;
    QString cars, city, test1;
    cars=ui->lineEdit_4->text();
    city=ui->lineEdit_3->text();
    test1 = QString("select * from maintance where company='%1' and city='%2'").arg(cars).arg(city);
    if(query.exec(test1)){
        while(query.next()){
            QString id=query.value(0).toString();
            QString city=query.value(1).toString();
            QString company=query.value(2).toString();
            QString tel=query.value(3).toString();
            int rowcount = ui->tableWidget_4->rowCount();
            ui->tableWidget_4->insertRow(rowcount);

            ui->tableWidget_4->setItem(rowcount,0,new QTableWidgetItem(id));
            ui->tableWidget_4->setItem(rowcount,1,new QTableWidgetItem(city));
            ui->tableWidget_4->setItem(rowcount,2,new QTableWidgetItem(company));
            ui->tableWidget_4->setItem(rowcount,3,new QTableWidgetItem(tel));
        }
    }

    ui->tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void filewindow::on_pushButton_8_clicked()
{
    ui->tableWidget_4->clearContents();
    int rowct=ui->tableWidget_4->rowCount();
    while(rowct--)
        ui->tableWidget_4->removeRow(rowct);
    this->InitTableWidget4();
}

void filewindow::getname(QString data){
    this->name=data;
    ui->label_2->setText(data);
}

void filewindow::on_pushButton_9_clicked()
{
    ui->tableWidget->clearContents();
    int rowct=ui->tableWidget->rowCount();
    while(rowct--)
        ui->tableWidget->removeRow(rowct);
    QSqlQuery query;
    QString min, max, test1, car;
    min=ui->txt_low->text();
    max=ui->txt_high->text();
    car=ui->comboBox->currentText();
    if(car=="")
        test1 = QString("select * from cars where cost>='%1' and cost<='%2'").arg(min.toInt()).arg(max.toInt());
    else
        test1 = QString("select * from cars where cost>='%1' and cost<='%2' and company ='%3'").arg(min.toInt()).arg(max.toInt()).arg(car);
    if(query.exec(test1)){
        while(query.next()){
            QString type=query.value(0).toString();
            QString fuel=query.value(1).toString();
            QString trans=query.value(2).toString();
            QString company=query.value(3).toString();
            QString cost=query.value(4).toString();
            QString num=query.value(5).toString();
            int rowcount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowcount);

            ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(type));
            ui->tableWidget->setItem(rowcount,1,new QTableWidgetItem(fuel));
            ui->tableWidget->setItem(rowcount,2,new QTableWidgetItem(trans));
            ui->tableWidget->setItem(rowcount,3,new QTableWidgetItem(company));
            ui->tableWidget->setItem(rowcount,4,new QTableWidgetItem(cost));
            ui->tableWidget->setItem(rowcount,5,new QTableWidgetItem(num));
        }
    }

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void filewindow::removeCombo(){
    int ct=ui->comboBox_2->count();
    for(int i=0;i<ct;++i)
        ui->comboBox_2->removeItem(0);
}

void filewindow::updatebuy(){
    ui->tableWidget_3->clearContents();
    int rowct=ui->tableWidget_3->rowCount();
    while(rowct--)
        ui->tableWidget_3->removeRow(rowct);
    QString test1, test2;
    QSqlQuery query1,query2;
    test1=QString("Select '预约',booktime,cartype,userid from book_record");
    test2=QString("Select '购买',buytime,cartype,userid from buy_record");
    if(query1.exec(test1)){
        while(query1.next()){
            QString type=query1.value(0).toString();
            QString fuel=query1.value(1).toString();
            QString trans=query1.value(2).toString();
            QString company=query1.value(3).toString();
            int rowcount = ui->tableWidget_3->rowCount();
            ui->tableWidget_3->insertRow(rowcount);

            ui->tableWidget_3->setItem(rowcount,0,new QTableWidgetItem(type));
            ui->tableWidget_3->setItem(rowcount,1,new QTableWidgetItem(fuel));
            ui->tableWidget_3->setItem(rowcount,2,new QTableWidgetItem(trans));
            ui->tableWidget_3->setItem(rowcount,3,new QTableWidgetItem(company));
        }
    }
    if(query2.exec(test2)){
        while(query2.next()){
            QString type=query2.value(0).toString();
            QString fuel=query2.value(1).toString();
            QString trans=query2.value(2).toString();
            QString company=query2.value(3).toString();
            int rowcount = ui->tableWidget_3->rowCount();
            ui->tableWidget_3->insertRow(rowcount);

            ui->tableWidget_3->setItem(rowcount,0,new QTableWidgetItem(type));
            ui->tableWidget_3->setItem(rowcount,1,new QTableWidgetItem(fuel));
            ui->tableWidget_3->setItem(rowcount,2,new QTableWidgetItem(trans));
            ui->tableWidget_3->setItem(rowcount,3,new QTableWidgetItem(company));
            }
        }
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void filewindow::on_pushButton_10_clicked()
{
    QString type;
    type=ui->comboBox_2->currentText();
    QSqlQuery query;
    QString test;
    test=QString("Insert into book_record values(getdate(),'%1','%2')").arg(type).arg(this->name);
    if(query.exec(test)){
        this->updatebuy();
        QMessageBox::information(this,"提示","恭喜您预约成功！\n预约记录为您保留30天");
    }
    else
        QMessageBox::critical(this,"提示","预约失败！\n请稍后再试");
}

void filewindow::on_pushButton_11_clicked()
{
    QPushButton *okbtn = new QPushButton("确定");
    QPushButton *cancelbtn = new QPushButton("再想想");
    QMessageBox *mymsgbox = new QMessageBox;

    mymsgbox->setIcon(QMessageBox::Warning);
    mymsgbox->setWindowTitle("提示");
    mymsgbox->setText("您是否确认了购买信息？");
    mymsgbox->addButton(okbtn, QMessageBox::AcceptRole);
    mymsgbox->addButton(cancelbtn, QMessageBox::RejectRole);
    mymsgbox->show();

    mymsgbox->exec();//阻塞等待用户输入
    if (mymsgbox->clickedButton()==cancelbtn)//点击了OK按钮
    {
        this->close();
    }
    else{
        QString type;
        type=ui->comboBox_2->currentText();
        QSqlQuery query;
        QString test;
        test=QString("Insert into buy_record values(getdate(),'%1','%2')").arg(type).arg(this->name);
        if(query.exec(test)){
            this->updatebuy();
            QMessageBox::information(this,"提示","购买成功！\n请尽快完成支付！");
            code2 *window = new code2;
            window->show();
        }
        else
            QMessageBox::critical(this,"提示","购买失败！\n请稍后再试");
    }
}


void filewindow::on_pushButton_12_clicked()
{
    QString type, way;
    type=ui->comboBox_2->currentText();
    QSqlQuery query;
    QString test;
    way=QString("维修");
    test=QString("Insert into repair_record values(getdate(),'%1','%2','%3')").arg(type).arg(this->name).arg(way);
    if(query.exec(test)){
        this->updatemend();
        QMessageBox::information(this,"提示","维修记录已保存！");
    }
    else
        QMessageBox::critical(this,"提示","操作失败！\n请稍后再试");
}

void filewindow::updatemend(){
    ui->tableWidget_5->clearContents();
    int rowct=ui->tableWidget_5->rowCount();
    while(rowct--)
        ui->tableWidget_5->removeRow(rowct);
    QString test;
    QSqlQuery query;
    test=QString("Select * from repair_record");
    if(query.exec(test)){
        while(query.next()){
            QString type=query.value(0).toString();
            QString fuel=query.value(1).toString();
            QString trans=query.value(2).toString();
            QString car=query.value(3).toString();
            int rowcount = ui->tableWidget_5->rowCount();
            ui->tableWidget_5->insertRow(rowcount);

            ui->tableWidget_5->setItem(rowcount,0,new QTableWidgetItem(type));
            ui->tableWidget_5->setItem(rowcount,1,new QTableWidgetItem(fuel));
            ui->tableWidget_5->setItem(rowcount,2,new QTableWidgetItem(trans));
            ui->tableWidget_5->setItem(rowcount,3,new QTableWidgetItem(car));
        }
    }
    ui->tableWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void filewindow::on_pushButton_13_clicked()
{
    QString type, way;
    type=ui->comboBox_2->currentText();
    QSqlQuery query;
    QString test;
    way=QString("保养");
    test=QString("Insert into repair_record values(getdate(),'%1','%2','%3')").arg(type).arg(this->name).arg(way);
    if(query.exec(test)){
        this->updatemend();
        QMessageBox::information(this,"提示","保养记录已保存！");
    }
    else
        QMessageBox::critical(this,"提示","操作失败！\n请稍后再试");
}

void filewindow::updatecmt(){
    ui->tableWidget_6->clearContents();
    int rowct=ui->tableWidget_6->rowCount();
    while(rowct--)
        ui->tableWidget_6->removeRow(rowct);
    QString test;
    QSqlQuery query;
    test=QString("Select * from comment");
    if(query.exec(test)){
        while(query.next()){
            QString type=query.value(0).toString();
            QString fuel=query.value(1).toString();
            QString trans=query.value(2).toString();
            int rowcount = ui->tableWidget_6->rowCount();
            ui->tableWidget_6->insertRow(rowcount);

            ui->tableWidget_6->setItem(rowcount,0,new QTableWidgetItem(type));
            ui->tableWidget_6->setItem(rowcount,1,new QTableWidgetItem(fuel));
            ui->tableWidget_6->setItem(rowcount,2,new QTableWidgetItem(trans));
        }
    }
    ui->tableWidget_6->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void filewindow::on_pushButton_14_clicked()
{
    QString cmt;
    cmt=ui->plainTextEdit->toPlainText();
    QSqlQuery query;
    QString test;
    test=QString("Insert into comment values('%1',getdate(),'%2')").arg(this->name).arg(cmt);
    if(query.exec(test)){
        this->updatecmt();
        ui->plainTextEdit->clear();
        QMessageBox::information(this,"提示","发表成功！");
    }
    else
        QMessageBox::critical(this,"提示","发表失败！\n请稍后再试");
}
