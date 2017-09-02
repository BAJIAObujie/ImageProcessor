#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFileInfoList>
#include "mypixmapitem.h"
#include "linearfilterdialog.h"
#include <vector>
#include "gauss_parameter.h"
#include "medianfilterdialog.h"
#include "bilateralfilterdlg.h"
#include "rotatedlg.h"
#include "logtransformdlg.h"
#include "lowpassfilterdlg.h"
#include "highpassfilterdlg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent* event);
private:
    Ui::MainWindow *ui;
    QFileDialog *fileDlg;
    QGraphicsScene *gs;
    MyPixmapItem *gpi;
    LinearFilterDialog *lfDlg;
    Gauss_parameter *GaussDlg;
    MedianFilterDialog *MedianDlg;
    bilateralFilterDlg *BilateralFilterDlg;
    RotateDlg *RotateDialog;
    LogTransformDlg *LogDlg;
    LowPassFilterDlg *LopDlg;
    HighPassFilterDlg *HipDlg;

    QFileInfoList images;
    int curIdx;

    void showImg(QImage);
    void reset();
    bool getDisplayedImage(QImage& img) const;
    static std::vector<double> parseMatrix1(QString, int&);
    static bool readOneRow(QString, std::vector<double>&, int&);
    static std::vector<double> parseMatrix2(QString, int&);


public slots:
    //-----------------------文件功能-保存图片-------------------
    void on_actionSaveImage_triggered();
    //-----------------------文件功能-保存图片-------------------

    //-----------------------基本操作-------------------
    void on_btnOpen_clicked();
    void on_btnReset_clicked();
    void on_btnPre_clicked();
    void on_btnNext_clicked();
    //-----------------------基本操作-------------------

    //-----------------------图像颜色处理-------------------
    void on_actionRGBToGray_triggered();
    void on_actionImageReversal_triggered();
    void on_actionLogTransform_triggered();
    void on_LogTransform_confirmed(double);
    void on_actionGrayToHist_triggered();
    void on_actionRGBToHist_triggered();
    void on_actionRGBToHSI_triggered();
    //-----------------------图像颜色处理-------------------


    //---------------线性滤波、高斯滤波、中值（膨胀腐蚀）滤波、双边滤波-------------
    void on_actionLinear_triggered();
    void on_LinearFilterDialog_confirmed(QString,bool);

    void on_actionGauss_triggered();
    void on_GaussDlg_confirmed(int,double,bool);

    void on_actionMedian_triggered();
    void on_MedianDlg_confirmed(int,bool,int);

    void on_actionBilateral_triggered();
    void on_BilaterFilterDlg_confirmed(int,double,double);
    //---------------线性滤波、高斯滤波、中值（膨胀腐蚀）滤波、双边滤波-------------

    //---------------图像频域------------------
    void on_actionSpectrum_triggered();
    void on_actionLowPassFilter_triggered();
    void on_LowPassFilter_confirmed(double);
    void on_actionHighPassFilter_triggered();
    void on_HighPassFilter_confirmed(double);

    //---------------图像频域------------------

    //---------------仿射变换------------------
    void on_actionAffine_triggered();
    void on_RotateDlg_confirmed(double,double,double,double,double,double,double,double,double);
    //---------------仿射变换------------------


};

#endif // MAINWINDOW_H
