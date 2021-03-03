#include "code.h"
#include "ui_code.h"

code::code(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::code)
{
    ui->setupUi(this);
}

code::~code()
{
    delete ui;
}
