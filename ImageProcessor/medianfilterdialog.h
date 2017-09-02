#ifndef MEDIANFILTERDIALOG_H
#define MEDIANFILTERDIALOG_H
#include <QDialog>
#include "QButtonGroup"
namespace Ui {
class MedianFilterDialog;
}

class MedianFilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MedianFilterDialog(QWidget *parent = 0);
    ~MedianFilterDialog();
    void initCheckBox();
private:
    Ui::MedianFilterDialog *ui;
    QButtonGroup* ButtonGroup;
public slots:
    void on_buttonBox_accepted();
    void ButtonGroup_change(int);
signals:
    void confirmed(int,bool,int);
};

#endif // MEDIANFILTERDIALOG_H
