#include "linearfilterdialog.h"
#include "ui_linearfilterdialog.h"

LinearFilterDialog::LinearFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinearFilterDialog)
{
    ui->setupUi(this);
}

LinearFilterDialog::~LinearFilterDialog()
{
    delete ui;
}

void LinearFilterDialog::accept()
{   bool isgrey = ui->radioButton->isChecked();
    emit confirmed(ui->textEdit->toPlainText(),isgrey);
    close();
}
