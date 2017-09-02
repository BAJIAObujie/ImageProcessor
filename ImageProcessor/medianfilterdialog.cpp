#include "medianfilterdialog.h"
#include "ui_medianfilterdialog.h"
#include "qdebug.h"

MedianFilterDialog::MedianFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MedianFilterDialog),
    ButtonGroup(new QButtonGroup(this))
{
    ui->setupUi(this);
    MedianFilterDialog::initCheckBox();
    connect(ButtonGroup,SIGNAL(buttonClicked(int)),this,SLOT(ButtonGroup_change(int)));
}

MedianFilterDialog::~MedianFilterDialog()
{
    delete ButtonGroup;
    delete ui;
}
void MedianFilterDialog::on_buttonBox_accepted(){
    bool ok;
    int c = ui->lineEdit->text().toInt(&ok);
    bool isgrey = ui->radioButton->isChecked();
    int d = ButtonGroup->checkedId();
    qDebug()<<d;
    if(ok)
        emit confirmed(c,isgrey,d);
}
void MedianFilterDialog::initCheckBox(){
    ButtonGroup->addButton(ui->checkBox,1);
    ButtonGroup->addButton(ui->checkBox_2,2);
    ButtonGroup->addButton(ui->checkBox_3,3);
}


void MedianFilterDialog::ButtonGroup_change(int x){
    switch (x) {
    case 1:
        ui->checkBox->setChecked(true);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        qDebug()<<"ui->checkBox";
        break;
    case 2:
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(true);
        ui->checkBox_3->setChecked(false);
        qDebug()<<"ui->checkBox_2";
        break;
    case 3:
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(true);
        qDebug()<<"ui->checkBox_3";
        break;
    default:
        break;
    }
}

