#include "logtransformdlg.h"
#include "ui_logtransformdlg.h"

LogTransformDlg::LogTransformDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogTransformDlg)
{
    ui->setupUi(this);
}

LogTransformDlg::~LogTransformDlg()
{
    delete ui;
}
void LogTransformDlg::on_buttonBox_accepted(){
    bool ok;
    double c = ui->lineEdit->text().toDouble(&ok);
    if(ok)
        emit confirmed(c);
}


