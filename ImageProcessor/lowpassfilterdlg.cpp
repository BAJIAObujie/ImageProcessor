#include "lowpassfilterdlg.h"
#include "ui_lowpassfilterdlg.h"

LowPassFilterDlg::LowPassFilterDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LowPassFilterDlg)
{
    ui->setupUi(this);
}

LowPassFilterDlg::~LowPassFilterDlg()
{
    delete ui;
}
void LowPassFilterDlg::on_buttonBox_accepted(){
    bool ok;
    double c = ui->lineEdit->text().toDouble(&ok);
    if(ok)
        emit confirmed(c);
}
