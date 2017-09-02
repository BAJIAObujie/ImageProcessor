#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H
#include <QImage>
#include <vector>
#include "matrix.h"
#include <qrgb.h>

struct HSI{
    double h;
    double s;
    double i;
};

class ImageProcessor
{
public:
    ImageProcessor();
    static QImage linearFilter(const QImage&, std::vector<double>, int,bool);
    static void kernelNormalization(std::vector<double>&);

    //高斯滤波
    static QImage gaussBlur(const QImage&,int,double,bool);
    static std::vector<double> createGaussKernel(int,double);
    //中值滤波
    static QImage medianFilter(const QImage&,int,bool,int);
    //双边滤波
    static QImage bilateralFilter(const QImage& ,int,double,double);
    static std::vector<double> createBilateralKernel(double);

    //图像频谱图
    static std::vector<std::complex<double> > fft(std::vector<int> data, size_t N );
    static std::vector<std::complex<double> > fft(std::vector<double> data, size_t N );
    static std::vector<std::complex<double> > fft(std::vector<std::complex<double> > data, size_t N );

    static Matrix<std::complex<double> > fftRow(const Matrix<std::complex<double> >&,size_t nRow,size_t nCol);

    static Matrix<complex<double> > fft2d(const Matrix<int>&, size_t, size_t);
    static Matrix<complex<double> > fft2d(const Matrix<double>&, size_t, size_t);
    static Matrix<complex<double> > fft2d(const Matrix<complex<double> >&, size_t, size_t);

    static complex<double> wnk(size_t ,int);
    static Matrix<int> absandlog_guiyi(const Matrix<complex<double> >&);//返回

    static QImage fftQImage(QImage&);
    static QImage fftLowPassFilterQImage(QImage& mat,double c);
    static QImage fftHighPassFilterQImage(QImage& mat,double c);



    //-------图像颜色处理

    static QImage RGBToGray(const QImage&);
    static QImage ImageReversal(const QImage&);
    static QImage LogTransform(const QImage&,double);
    static QImage GrayToHist(const QImage&);
    static QImage RGBToHist(const QImage&);
    static QImage RGBToHSI(const QImage&);
    static void rgb2hsi(QRgb rgb,HSI& hsi);
    static void hsi2rgb(HSI hsi,int& r,int& g,int& b);
    static double Hue_2_RGB(double v1,double v2,double vh);

    //-------图像颜色处理




    //-------仿射变换------

    static QImage affineTransformMatrix(QImage&,QMatrix&);
      //-------获得新图像的范围
    static void getRange(QMatrix&,double,double,double&,double&,double&,double&);
    static QRgb getColor(QImage& img,QMatrix& mat,int x,int y,double MinX,double MinY);
    static QRgb bilinear(QImage& img,double x,double y);
    static double bilinear_cal(double v1,double v2,double c1,double c2,double c3);

    //-------仿射变换------


private:
    //高斯滤波
    static QImage zeroPadding(const QImage&, int, int);
    static QImage filter(const QImage&, std::vector<double>, int, int,bool);
    static std::vector<int> getPatch(const QImage&, int, int, int, int, char);
    static QImage crop(const QImage&, int, int);
    //中值滤波
    static QImage medianfilter(const QImage&,int,bool,int);

    //边缘填充
    static QImage Duplication(const QImage&, int,int);
    static QImage MirrorCopy(const QImage&, int, int);



    //图像频谱图
    static size_t calcN(size_t length);
    //static std::complex<double> pow(std::complex<double> base, int exponent);
};


#endif // IMAGEPROCESSOR_H
