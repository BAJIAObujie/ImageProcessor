#include "bilateralfilterdlg.h"
#include "ui_bilateralfilterdlg.h"

bilateralFilterDlg::bilateralFilterDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bilateralFilterDlg)
{
    ui->setupUi(this);
}

bilateralFilterDlg::~bilateralFilterDlg()
{
    delete ui;
}
void bilateralFilterDlg::on_buttonBox_accepted(){
    bool ok_int_size;
    bool ok_double_sigmaspace;
    bool ok_double_sigmacolor;
    int c = ui->lineEdit->text().toInt(&ok_int_size);
    double d = ui->lineEdit_2->text().toDouble(&ok_double_sigmaspace);
    double e = ui->lineEdit_3->text().toDouble(&ok_double_sigmacolor);
    if(ok_int_size&&ok_double_sigmacolor&&ok_double_sigmaspace)
        emit confirmed(c,d,e);
}
//lineEdit_3
