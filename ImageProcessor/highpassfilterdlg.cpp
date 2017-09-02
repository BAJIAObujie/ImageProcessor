#include "highpassfilterdlg.h"
#include "ui_highpassfilterdlg.h"

HighPassFilterDlg::HighPassFilterDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighPassFilterDlg)
{
    ui->setupUi(this);
}

HighPassFilterDlg::~HighPassFilterDlg()
{
    delete ui;
}
void HighPassFilterDlg::on_buttonBox_accepted(){
    bool ok;
    double c = ui->lineEdit->text().toDouble(&ok);
    if(ok)
        emit confirmed(c);
}
