#ifndef ROTATEDLG_H
#define ROTATEDLG_H

#include <QDialog>

namespace Ui {
class RotateDlg;
}

class RotateDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RotateDlg(QWidget *parent = 0);
    ~RotateDlg();

private:
    Ui::RotateDlg *ui;


public slots:
    void on_buttonBox_accepted();
signals:
    void confirmed(double,double,double,double,double,double,double,double,double);
};

#endif // ROTATEDLG_H
