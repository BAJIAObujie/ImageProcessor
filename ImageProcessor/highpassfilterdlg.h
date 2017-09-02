#ifndef HIGHPASSFILTERDLG_H
#define HIGHPASSFILTERDLG_H

#include <QDialog>

namespace Ui {
class HighPassFilterDlg;
}

class HighPassFilterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit HighPassFilterDlg(QWidget *parent = 0);
    ~HighPassFilterDlg();

private:
    Ui::HighPassFilterDlg *ui;
public slots:
    void on_buttonBox_accepted();
signals:
    void confirmed(double);
};

#endif // HIGHPASSFILTERDLG_H
