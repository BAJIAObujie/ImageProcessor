#include "gauss_parameter.h"
#include "ui_gauss_parameter.h"

Gauss_parameter::Gauss_parameter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gauss_parameter)
{
    ui->setupUi(this);
}

Gauss_parameter::~Gauss_parameter()
{
    delete ui;
}
void Gauss_parameter::on_buttonBox_accepted(){
    bool ok_int;
    bool ok_double;

    int c = ui->lineEdit->text().toInt(&ok_int);
    double d = ui->lineEdit_2->text().toDouble(&ok_double);
    bool isgrey = ui->radioButton->isChecked();
    if(ok_int&&ok_double)
        emit confirmed(c,d,isgrey);
}


