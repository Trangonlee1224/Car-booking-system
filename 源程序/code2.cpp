#include "code2.h"
#include "ui_code2.h"

code2::code2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::code2)
{
    ui->setupUi(this);
}

code2::~code2()
{
    delete ui;
}
