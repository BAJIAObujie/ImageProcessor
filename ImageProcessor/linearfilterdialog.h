#ifndef LINEARFILTERDIALOG_H
#define LINEARFILTERDIALOG_H

#include <QDialog>


namespace Ui {
class LinearFilterDialog;
}

class LinearFilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LinearFilterDialog(QWidget *parent = 0);
    ~LinearFilterDialog();

public slots:
    void accept();

private:
    Ui::LinearFilterDialog *ui;

signals:
    void confirmed(QString,bool);
};

#endif // LINEARFILTERDIALOG_H
