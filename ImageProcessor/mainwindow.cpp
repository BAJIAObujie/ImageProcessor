#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QImage>
#include <QDir>
#include <QRegularExpression>
#include <QRegularExpressionMatchIterator>
#include "imageprocessor.h"
#include "qdebug.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    fileDlg(new QFileDialog(this)),
    lfDlg(new LinearFilterDialog(this)),
    GaussDlg(new Gauss_parameter(this)),
    MedianDlg(new MedianFilterDialog(this)),
    BilateralFilterDlg(new bilateralFilterDlg(this)),
    RotateDialog(new RotateDlg(this)),
    LogDlg(new LogTransformDlg(this)),
    LopDlg(new LowPassFilterDlg(this)),
    HipDlg(new HighPassFilterDlg(this)),

    gs(NULL),
    gpi(NULL)
{
    ui->setupUi(this);
    connect(lfDlg,SIGNAL(confirmed(QString,bool)),this,SLOT(on_LinearFilterDialog_confirmed(QString,bool)));
    connect(GaussDlg,SIGNAL(confirmed(int,double,bool)),this,SLOT(on_GaussDlg_confirmed(int,double,bool)));
    connect(MedianDlg,SIGNAL(confirmed(int,bool,int)),this,SLOT(on_MedianDlg_confirmed(int,bool,int)));
    connect(BilateralFilterDlg,SIGNAL(confirmed(int,double,double)),
            this,SLOT(on_BilaterFilterDlg_confirmed(int,double,double)));
    connect(LogDlg,SIGNAL(confirmed(double)),this,SLOT(on_LogTransform_confirmed(double)));
    connect(LopDlg,SIGNAL(confirmed(double)),this,SLOT(on_LowPassFilter_confirmed(double)));
    connect(HipDlg,SIGNAL(confirmed(double)),this,SLOT(on_HighPassFilter_confirmed(double)));
    //connect(RotateDialog,SIGNAL(confirmed(double,double,double,double,double,double,double,double,double)),
    //        this,SLOT(on_RotateDlg_confirmed(double,double,double,double,double,double,double,double,double)));
}

MainWindow::~MainWindow()
{
    delete gpi;
    delete gs;
    delete fileDlg;
    delete lfDlg;
    delete GaussDlg;
    delete MedianDlg;
    delete BilateralFilterDlg;
    delete RotateDialog;
    delete LogDlg;
    delete LopDlg;
    delete HipDlg;
    delete ui;
}
void MainWindow::resizeEvent(QResizeEvent* event){
    if(NULL==gpi)
        return;
    reset();
}
void MainWindow::on_btnOpen_clicked()
{
    if (fileDlg->exec())
    {
        QStringList files = fileDlg->selectedFiles();
        QDir dir = fileDlg->directory();
        QStringList filters;
        filters << "*.jpg" << "*.png";
        images = dir.entryInfoList(filters);
        for(int i=0; i<images.length(); ++i)
            if (images[i].absoluteFilePath() == files[0])
                curIdx = i;
        showImg(QImage(images[curIdx].absoluteFilePath()));
    }
}

void MainWindow::on_btnReset_clicked()
{
    reset();
}

void MainWindow::showImg(QImage img)
{
    if (NULL != gpi)
    {
        delete gpi;
        gpi = NULL;
    }
    if(NULL != gs)
    {
        delete gs;
        gs = NULL;
    }

    gpi = new MyPixmapItem();
    gpi->setPixmap(QPixmap::fromImage(img));

    gs = new QGraphicsScene(this);
    gs->addItem(gpi);

    ui->graphicsView->setScene(gs);

    reset();
}

void MainWindow::on_btnPre_clicked()
{
    if (0 == images.length())
        return;
    if(0 == curIdx)
        curIdx = images.length();
    showImg(QImage(images[--curIdx].absoluteFilePath()));
}

void MainWindow::on_btnNext_clicked()
{
    if (0 == images.length())
        return;
    if(images.length()-1 == curIdx)
        curIdx = -1;
    showImg(QImage(images[++curIdx].absoluteFilePath()));
}

void MainWindow::reset()
{
    if(gpi)
    {
        gpi->reset();
        QRectF rect = gpi->boundingRect();
        gs->setSceneRect(rect);
        ui->graphicsView->fitInView(rect, Qt::KeepAspectRatio);
    }
}

bool MainWindow::getDisplayedImage(QImage& img) const
{
    if (gpi)
    {
        QList<QGraphicsItem*> items = ui->graphicsView->scene()->items();
        QGraphicsPixmapItem* item = (QGraphicsPixmapItem*)items.at(0);
        img = item->pixmap().toImage();
        return true;
    }
    return false;
}

void MainWindow::on_actionLinear_triggered()
{
    lfDlg->exec();
}

vector<double> MainWindow::parseMatrix2(QString txt, int& nCol)
{
    vector<double> ret;
    QRegularExpression reRow("[-\\d\\.\\s,]+;?");
    QRegularExpression reCol("-?\\d*\\.?\\d+[,|\\s]?");
    QRegularExpressionMatchIterator remiRow = reRow.globalMatch(txt);
    nCol = -1;
    while(remiRow.hasNext())
    {
        QString row = remiRow.next().captured().replace(";","").trimmed();
        if (row.isEmpty())  continue;
        QRegularExpressionMatchIterator remiCol = reCol.globalMatch(row);
        int tmp = 0;
        while(remiCol.hasNext())
        {
            QString col = remiCol.next().captured().replace(",","").trimmed();
            if (col.isEmpty())  continue;
            bool ok;
            double d = col.toDouble(&ok);
            if(ok)
            {
                ret.push_back(d);
                tmp++;
            }
            else
                return vector<double>();
        }
        if(-1==nCol)    nCol = tmp;
        else if (nCol != tmp)   return vector<double>();
    }
    return ret;
}

vector<double> MainWindow::parseMatrix1(QString txt, int& nCol)
{
    vector<double> ret;
    QRegularExpression reRow("[-\\d\\.\\s,]+;?");
    QRegularExpression reCol("-?\\d*\\.?\\d+[,|\\s]?");
    QRegularExpressionMatchIterator remiRow = reRow.globalMatch(txt);
    while(remiRow.hasNext()) {
            QString row = remiRow.next().captured().replace(";","").trimmed();
            if (row.isEmpty()) continue;
            QRegularExpressionMatchIterator remiCol = reCol.globalMatch(row);
            nCol = -1;
            int tmp = 0;
            while(remiCol.hasNext()) {
               QString col = remiCol.next().captured().replace(",","").trimmed();
               if (col.isEmpty()) continue;
               bool ok;
               double d = col.toDouble(&ok);
               if(ok) {
                  ret.push_back(d);
                  tmp++;
                  }
               else
                   return vector<double>();
            }
            if(-1==nCol) nCol = tmp;
            else if (nCol != tmp) return vector<double>();
            }
            return ret;
}

bool MainWindow::readOneRow(QString row, std::vector<double>& kernel, int& nCol)
{
    nCol = 0;
    // split into number by , and \s
    QStringList cols = row.trimmed().split(QRegularExpression("\\s*,|\\s+"));
    for(int j=0; j<cols.size(); ++j)
    {
        // parse each col
        bool ok;
        QString col = cols[j];
        if (col.trimmed().isEmpty())    continue;
        double d = col.trimmed().toDouble(&ok);
        if(ok)
        {
            nCol++;
            kernel.push_back(d);
        }
        else
        {
            return false;
        }
    }
    return true;
}

void MainWindow::on_LinearFilterDialog_confirmed(QString txt,bool isgrey)
{
    int nCol;
    cout<<"linear filter"<<endl;
    vector<double> kernel = parseMatrix1(txt, nCol);
    cout<< nCol <<endl;
    ImageProcessor::kernelNormalization(kernel);
    if(-1==nCol)    return;
    QImage img;
    bool ok = getDisplayedImage(img);
    if(ok)
        showImg(ImageProcessor::linearFilter(img, kernel, nCol,isgrey));
}



void MainWindow::on_actionGauss_triggered(){
    GaussDlg->exec();
}
void MainWindow::on_GaussDlg_confirmed(int size, double sigma,bool isgrey){
    QImage img;
    bool ok = getDisplayedImage(img);
    if(ok)
        showImg(ImageProcessor::gaussBlur(img,size,sigma,isgrey));
        //QImage gaussBlur(const QImage&,int,double);
}

void MainWindow::on_actionMedian_triggered(){
    MedianDlg->exec();
    //MedianDlg->initCheckBox();
}
void MainWindow::on_MedianDlg_confirmed(int c,bool isgrey,int d){
    qDebug() << c ;

    QImage img;
    bool ok = getDisplayedImage(img);
    if(ok){
        showImg(ImageProcessor::medianFilter(img,c,isgrey,d));
    }
}

void MainWindow::on_actionBilateral_triggered(){
    BilateralFilterDlg->exec();
}
void MainWindow::on_BilaterFilterDlg_confirmed(int size,double sigmaspace,double sigmacolor){
    QImage img;
    bool ok = getDisplayedImage(img);
    if(ok){
        //showImg(ImageProcessor::bilateralFilter(img,size,sigmaspace,sigmacolor));
        showImg(MatrixbilateralFilter(img,size,sigmaspace,sigmacolor));
    }
}

//图像频谱图
void MainWindow::on_actionSpectrum_triggered(){
    QImage img;
    bool ok = getDisplayedImage(img);
    if(ok){
        showImg(ImageProcessor::fftQImage(img));
    // fftshift (log(1 + abs(fft2(imread (...))))),[]); matlab
    }
}

//---------------仿射变换------------------------------
void MainWindow::on_actionAffine_triggered(){
     RotateDialog->exec();
}
void MainWindow::on_RotateDlg_confirmed(double one,double two,double three,double four,double five,
                                        double six,double seven,double eight,double nine){
    //cout<<one<<endl;
    //cout<<eight<<endl;
    QMatrix mat;
    mat.setMatrix(one,two,  four,five,  seven,eight  );
    QImage img;
    bool isInvertible = mat.isInvertible();
    if(isInvertible){
        bool ok = getDisplayedImage(img);
        if(ok){
           //showImg(ImageProcessor::affineTransformMatrix(img,mat));
            showImg(MatrixaffineTransformMatrix(img,mat));
        }
    }
    else{
        cout<<"isInvertible : "+isInvertible<<endl;
    }
}
//------------------------------

//------------------------图像颜色变换------------
void MainWindow::on_actionRGBToGray_triggered(){
    QImage img;
    bool ok = getDisplayedImage(img);
    if(ok)
        //showImg(ImageProcessor::RGBToGray(img));
        showImg(MatrixRGBToGray(img)); //矩阵成功
}
void MainWindow::on_actionImageReversal_triggered(){
    QImage img;
    bool ok;
    ok = MainWindow::getDisplayedImage(img);
    if(ok){
        //showImg(ImageProcessor::ImageReversal(img));
        showImg(MatrixImageReversal(img)); //矩阵成功
    }
}

void MainWindow::on_actionLogTransform_triggered(){
    LogDlg->exec();
}
void MainWindow::on_LogTransform_confirmed(double c){
    QImage img;
    bool ok;
    ok = MainWindow::getDisplayedImage(img);
    if(ok){
        //showImg(ImageProcessor::LogTransform(img,c));
        showImg(MatrixLogTransform(img,c));//矩阵成功
    }
}
void MainWindow::on_actionGrayToHist_triggered(){
    QImage img;
    bool ok;
    ok = MainWindow::getDisplayedImage(img);
    if(ok){
        //showImg(ImageProcessor::GrayToHist(img));
        showImg(MatrixGrayToHist(img));//矩阵成功
    }
}

void MainWindow::on_actionRGBToHist_triggered(){
    QImage img;
    bool ok;
    ok = MainWindow::getDisplayedImage(img);
    if(ok){
        //showImg(ImageProcessor::RGBToHist(img));
        showImg(MatrixRGBToHist(img));//矩阵成功，之前的RGBToHist中最后做均衡的时候是三个qRed，导致RGB均衡是错误的，现在已经发现并改正过来。
    }
}

void MainWindow::on_actionRGBToHSI_triggered(){
    QImage img;
    bool ok;
    ok = MainWindow::getDisplayedImage(img);
    if(ok){
        showImg(ImageProcessor::RGBToHSI(img));
    }
}
//------------------------图像颜色变换------------

//------------------------保存图片---------------作业要求四完成-----
void MainWindow::on_actionSaveImage_triggered(){
    QImage img;
    bool ok;
    ok = MainWindow::getDisplayedImage(img);
    if(ok){
        QString filename = QFileDialog::getSaveFileName
                (this,tr("另存为"),"未命名",tr( "(*.jpg);;(*.png);;(*.bmp);;All files (*.*)")); 
        //选择保存路径 当前窗口 另存为 默认名字：未命名 选择格式
        if(filename.isEmpty())
        {
            return;
            cout<<"You are expected to write down a filename"<<endl;
        }
        else
        {
            img.save(filename);
            cout<<"Saving image finish"<<endl;
        }
    }
}
//-----------------------保存图片结束------------------------

//-----------------------低通高通滤波------------------------
void MainWindow::on_actionLowPassFilter_triggered(){
    LopDlg->exec();

}
void MainWindow::on_LowPassFilter_confirmed(double c){
    QImage img;
    bool ok;
    ok = MainWindow::getDisplayedImage(img);
    if(ok){
        showImg(ImageProcessor::fftLowPassFilterQImage(img,c));
        //cout<<c<<endl;
    }
}
void MainWindow::on_actionHighPassFilter_triggered(){
    HipDlg->exec();

}
void MainWindow::on_HighPassFilter_confirmed(double c){
    QImage img;
    bool ok;
    ok = MainWindow::getDisplayedImage(img);
    if(ok){
        showImg(ImageProcessor::fftHighPassFilterQImage(img,c));
        //cout<<c<<endl;
    }
}
//-----------------------低通高通滤波------------------------
