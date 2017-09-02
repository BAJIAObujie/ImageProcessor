#ifndef GAUSS_PARAMETER_H
#define GAUSS_PARAMETER_H

#include <QDialog>

namespace Ui {
class Gauss_parameter;
}

class Gauss_parameter : public QDialog
{
    Q_OBJECT

public:
    explicit Gauss_parameter(QWidget *parent = 0);
    ~Gauss_parameter();

private:
    Ui::Gauss_parameter *ui;

public slots:
    void on_buttonBox_accepted();
signals:
    void confirmed(int,double,bool);
};

#endif // GAUSS_PARAMETER_H
