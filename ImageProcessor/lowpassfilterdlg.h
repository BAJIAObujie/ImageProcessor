#ifndef LOWPASSFILTERDLG_H
#define LOWPASSFILTERDLG_H

#include <QDialog>

namespace Ui {
class LowPassFilterDlg;
}

class LowPassFilterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LowPassFilterDlg(QWidget *parent = 0);
    ~LowPassFilterDlg();

private:
    Ui::LowPassFilterDlg *ui;
public slots:
    void on_buttonBox_accepted();
signals:
    void confirmed(double);
};

#endif // LOWPASSFILTERDLG_H
