#ifndef BILATERALFILTERDLG_H
#define BILATERALFILTERDLG_H

#include <QDialog>

namespace Ui {
class bilateralFilterDlg;
}

class bilateralFilterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit bilateralFilterDlg(QWidget *parent = 0);
    ~bilateralFilterDlg();

private:
    Ui::bilateralFilterDlg *ui;

public slots:
    void on_buttonBox_accepted();
signals:
    void confirmed(int,double,double);

};

#endif // BILATERALFILTERDLG_H
