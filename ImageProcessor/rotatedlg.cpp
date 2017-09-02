#include "rotatedlg.h"
#include "ui_rotatedlg.h"

RotateDlg::RotateDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RotateDlg)
{
    ui->setupUi(this);
}

RotateDlg::~RotateDlg()
{
    delete ui;
}
void RotateDlg::on_buttonBox_accepted(){
    bool ok_one;
    bool ok_two;
    bool ok_three;
    bool ok_four;
    bool ok_five;
    bool ok_six;
    bool ok_seven;
    bool ok_eight;
    bool ok_nine;

    double one = ui->lineEdit->text().toDouble(&ok_one);
    double two = ui->lineEdit_2->text().toDouble(&ok_two);
    double three = ui->lineEdit_3->text().toDouble(&ok_three);
    double four = ui->lineEdit_4->text().toDouble(&ok_four);
    double five = ui->lineEdit_5->text().toDouble(&ok_five);
    double six = ui->lineEdit_6->text().toDouble(&ok_six);
    double seven = ui->lineEdit_7->text().toDouble(&ok_seven);
    double eight = ui->lineEdit_8->text().toDouble(&ok_eight);
    double nine = ui->lineEdit_9->text().toDouble(&ok_nine);

    if(ok_one&&ok_two&&ok_three&&ok_four&&ok_five&&ok_six&&ok_seven&&ok_eight&&ok_nine)
        emit confirmed(one,two,three,four,five,six,seven,eight,nine);
}
