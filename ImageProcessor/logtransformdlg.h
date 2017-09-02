#ifndef LOGTRANSFORMDLG_H
#define LOGTRANSFORMDLG_H

#include <QDialog>

namespace Ui {
class LogTransformDlg;
}

class LogTransformDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LogTransformDlg(QWidget *parent = 0);
    ~LogTransformDlg();

private:
    Ui::LogTransformDlg *ui;
public slots:
    void on_buttonBox_accepted();
signals:
    void confirmed(double);

};

#endif // LOGTRANSFORMDLG_H
