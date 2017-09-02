#include "imageprocessor.h"
#include <iostream>
#include <QRgb>
#include <cmath>
#include <QtCore/qmath.h>
#include <cstdarg>
#include <algorithm>
#include "qdebug.h"
#include "matrix.h"

ImageProcessor::ImageProcessor()
{

}

QImage ImageProcessor::linearFilter(const QImage& img, std::vector<double> kernel, int nCol,bool isgrey)
{
    int nRow = kernel.size() / nCol;
    if (0 == nRow%2 || 0 == nCol%2) return img;

    //当时这里是有三种边缘填充方法，之前这里选用了第一种，但没有放出控件到界面上，所以注释掉，选用第一种padding方式。
    //padding
    //QImage padded = zeroPadding(img, nCol, nRow);
    QImage padded = MatrixzeroPadding(img, nCol, nRow);//矩阵完成

    // Duplication
    //QImage padded = Duplication(img, nCol, nRow);

    // MirrorCopy
    //QImage padded = MirrorCopy(img, nCol, nRow);

    // filter
    //QImage filtered = filter(padded, kernel, nCol, nRow,isgrey);
    QImage filtered = Matrixfilter(padded, kernel, nCol, nRow,isgrey);//测试中

    // crop
    //QImage croped = crop(filtered, nCol, nRow);
    QImage croped = Matrixcrop(filtered, nCol, nRow);//矩阵完成

    return croped;
}

QImage ImageProcessor::zeroPadding(const QImage& img, int nCol, int nRow)
{
    QImage ret(img.width()+nCol-1, img.height()+nRow-1, img.format());
    int width = ret.width();
    int height = ret.height();
    for(int i=0; i<width; ++i)
    {
        for(int j=0; j<height; ++j)
        {
            if(i<nCol/2 || i>=width-nCol/2 ||
                    j<nRow/2 || j>=height-nRow/2)
                ret.setPixel(i, j ,qRgb(0,0,0));
            else
                ret.setPixel(i, j, img.pixel(i-nCol/2, j-nRow/2));
        }
    }
    return ret;
}

QImage ImageProcessor::Duplication(const QImage & img, int nCol, int nRow){
    QImage ret(img.width()+nCol-1, img.height()+nRow-1, img.format());
    int width = ret.width();
    int height = ret.height();
    for(int i=0; i<width; ++i)
        for(int j=0; j<height; ++j){
              if(j<nRow/2){
                if(i<nCol/2){
                    QRgb rgb = img.pixel(0,0);
                    ret.setPixel(i,j,rgb);
                }
                if(nCol/2<=i && i<width-nCol/2 ){
                    QRgb rgb = img.pixel(i-nCol/2,0);
                    ret.setPixel(i,j,rgb);
                }
                if(i>width-nCol/2 ){
                    QRgb rgb = img.pixel(img.width()-1,0);
                    ret.setPixel(i,j,rgb);
                }
            }
              if(j>=nRow/2 && j<height-nRow/2){
                  if(i<nCol/2){
                      QRgb rgb = img.pixel(0,j-nRow/2);
                      ret.setPixel(i,j,rgb);
                  }
                  if(nCol/2<=i && i<width-nCol/2 ){
                      QRgb rgb = img.pixel(i-nCol/2,j-nRow/2);
                      ret.setPixel(i,j,rgb);
                  }
                  if(i>width-nCol/2){
                      QRgb rgb = img.pixel(img.width()-1,j-nRow/2);
                      ret.setPixel(i,j,rgb);
                  }
              }
              if(j>=height-nRow/2){
                  if(i<nCol/2){
                      QRgb rgb = img.pixel(0,img.height()-1);
                      ret.setPixel(i,j,rgb);
                  }
                  if(nCol/2<=i && i<width-nCol/2 ){
                      QRgb rgb = img.pixel(i-nCol/2,img.height()-1);
                      ret.setPixel(i,j,rgb);
                  }
                  if(i>width-nCol/2 ){
                      QRgb rgb = img.pixel(img.width()-1,img.height()-1);
                      ret.setPixel(i,j,rgb);
                  }
              }
        }
    return ret;
}
QImage ImageProcessor::MirrorCopy(const QImage& img, int nCol, int nRow){
    QImage ret(img.width()+nCol-1, img.height()+nRow-1, img.format());
    int width = ret.width();
    int height = ret.height();
    for(int i=0; i<width; i++)
        for(int j=0; j<height; j++){
              if(j<nRow/2){
                if(i<nCol/2){
                    QRgb rgb = img.pixel(nCol/2-i,nRow/2-j);
                    ret.setPixel(i,j,rgb);
                }
                if(nCol/2<=i && i<width-nCol/2 ){
                    QRgb rgb = img.pixel(i-nCol/2,nRow/2-j);
                    ret.setPixel(i,j,rgb);
                }
                if(i>width-nCol/2 ){
                    QRgb rgb = img.pixel(2*width-(3*(nCol-1))/2-2-i,nRow/2-j);
                    ret.setPixel(i,j,rgb);
                }
            }
              if(j>=nRow/2 && j<height-nRow/2){
                  if(i<nCol/2){
                      QRgb rgb = img.pixel(nCol/2-i,j-nRow/2);
                      ret.setPixel(i,j,rgb);
                  }
                  if(nCol/2<=i && i<width-nCol/2 ){
                      QRgb rgb = img.pixel(i-nCol/2,j-nRow/2);
                      ret.setPixel(i,j,rgb);
                  }
                  if(i>width-nCol/2){
                      QRgb rgb = img.pixel(2*width-(3*(nCol-1))/2-2-i,j-nRow/2);
                      ret.setPixel(i,j,rgb);
                  }
              }
              if(j>=height-nRow/2){
                  if(i<nCol/2){
                      QRgb rgb = img.pixel(nCol/2-i,2*height-(3*(nRow-1))/2-2-j);
                      ret.setPixel(i,j,rgb);
                  }
                  if(nCol/2<=i && i<width-nCol/2 ){
                      QRgb rgb = img.pixel(i-nCol/2,2*height-(3*(nRow-1))/2-2-j);
                      ret.setPixel(i,j,rgb);
                  }
                  if(i>width-nCol/2 ){
                      QRgb rgb = img.pixel(2*width-(3*(nCol-1))/2-2-i,2*height-(3*(nRow-1))/2-2-j);
                      ret.setPixel(i,j,rgb);
                  }
              }
        }
    return ret;
}
QImage ImageProcessor::crop(const QImage& img, int nCol, int nRow)
{
    QImage ret(img.width()-nCol+1, img.height()-nRow+1, img.format());
    int width = ret.width();
    int height = ret.height();
    for(int i=0; i<width; ++i)
    {
        for(int j=0; j<height; ++j)
        {
            ret.setPixel(i, j, img.pixel(i+nCol/2, j+nRow/2));
        }
    }
    return ret;
}

QImage ImageProcessor::filter(const QImage& img, std::vector<double> kernel, int nCol, int nRow,bool isgrey)
{
    QImage ret(img);
    int width = img.width();
    int height = img.height();
    for(int i=nCol/2; i<width-nCol/2; ++i)
    {
        for(int j=nRow/2; j<height-nRow/2; ++j)
        {
            if(isgrey){
                std::vector<int> patchY = getPatch(img, i, j, nCol, nRow, 'y');
                double sumY = 0;
                for(int k=0; k<kernel.size(); ++k)
                    sumY += kernel[k]*patchY[k];
                int y = (int)sumY;

                if (y>255)   y = 255;
                if(y<0) y=0;
                ret.setPixel(i,j, qRgb(y,y,y));
            }
            else{
                std::vector<int> patchR = getPatch(img, i, j, nCol, nRow, 'r');
                std::vector<int> patchG = getPatch(img, i, j, nCol, nRow, 'g');
                std::vector<int> patchB = getPatch(img, i, j, nCol, nRow, 'b');
                double sumR = 0, sumG = 0, sumB = 0;
                for(int k=0; k<kernel.size(); ++k)
                {
                    sumR += kernel[k]*patchR[k];
                    sumG += kernel[k]*patchG[k];
                    sumB += kernel[k]*patchB[k];
                }
                int r = (int)sumR;
                int g = (int)sumG;
                int b = (int)sumB;
                if (r>255)   r = 255;
                if (g>255)   g = 255;
                if (b>255)   b = 255;
                if(r<0) r=0;
                if(g<0) g=0;
                if(b<0) b=0;
                ret.setPixel(i,j, qRgb(r, g, b));
            }

        }
    }
    return ret;
}

std::vector<int> ImageProcessor::getPatch(const QImage& img, int w, int h, int nCol, int nRow, char c)
{
    std::vector<int> ret;
    for(int i=w-nCol/2; i<=w+nCol/2; ++i)
    {
        for(int j=h-nRow/2; j<=h+nRow/2; ++j)
        {
            switch (c) {
            case 'r':
                ret.push_back(qRed(img.pixel(i, j)));
                break;
            case 'g':
                ret.push_back(qGreen(img.pixel(i, j)));
                break;
            case 'b':
                ret.push_back(qBlue(img.pixel(i, j)));
                break;
            case 'y':
                ret.push_back(qGray(img.pixel(i, j)));
                break;
            default:
                break;
            }
        }
    }
    return ret;
}

void ImageProcessor::kernelNormalization(std::vector<double>& kernel)
{
    double sum = 0;
    for(int i=0; i<kernel.size(); ++i)
        sum+=kernel[i];
    if(0!=sum)
    {
        for(int i=0; i<kernel.size(); ++i)
            kernel[i] /= sum;
    }
}

QImage ImageProcessor::gaussBlur(const QImage& img,int size,double sigma,bool isgrey){
    std::vector<double> kernel = createGaussKernel(size,sigma);
    kernelNormalization(kernel);
    return ImageProcessor::linearFilter(img, kernel, size,isgrey);
}

std::vector<double> ImageProcessor::createGaussKernel(int size,double sigma){
    double const PI=3.1415926;
    std::vector<double> ret;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            int deltaX=abs(i-size/2);
            int deltaY=abs(j-size/2);
            double val=1/(2*PI*sigma*sigma);
            double cc =val*exp((-deltaX*deltaX-deltaY*deltaY)/(2*sigma*sigma));
            ret.push_back(cc);
        }
    }
    return ret;
}
QImage ImageProcessor::medianFilter(const QImage& img, int size,bool isgrey,int three){

    // padding
    //QImage padded = zeroPadding(img, size, size);//图像的边缘补零
    QImage padded = MatrixzeroPadding(img, size, size);//矩阵的边缘补零

    // filter
    //QImage filtered = medianfilter(padded,size,isgrey,three);
    QImage filtered = Matrixmedianfilter(padded,size,isgrey,three);

    // crop
    //QImage croped = crop(filtered,size,size);
    QImage croped = Matrixcrop(filtered,size,size);
    return croped;

}

QImage ImageProcessor::medianfilter(const QImage& img, int size,bool isgrey,int three){
    QImage ret(img);
    int width = img.width();
    int height = img.height();
    int r,g,b,y;
    //grey
    if(isgrey){
            for(int i=size/2; i<width-size/2; ++i)
            {
                for(int j=size/2; j<height-size/2; ++j)
                {
                    std::vector<int> patchY = getPatch(img, i, j, size, size, 'y');
                    std::sort(patchY.begin(),patchY.end());
                    switch (three) {
                    case 1:  //Mediam grey
                        y = patchY.at(patchY.size()/2);
                        break;
                    case 2:  //Dilation grey
                        y = patchY.at(patchY.size()-1);
                        break;
                    case 3:  //Erosion grey
                        y = patchY.at(0);
                        break;
                    default:
                        break;
                    }
                    if (y>255)   y = 255;
                    if(y<0) y=0;
                    ret.setPixel(i,j, qRgb(y,y,y));
                }
            }
    }
    //not grey
    else{
            for(int i=size/2; i<width-size/2; ++i)
            {
                for(int j=size/2; j<height-size/2; ++j)
                {
                    std::vector<int> patchR = getPatch(img, i, j, size, size, 'r');
                    std::vector<int> patchG = getPatch(img, i, j, size, size, 'g');
                    std::vector<int> patchB = getPatch(img, i, j, size, size, 'b');

                    std::sort(patchR.begin(),patchR.end());
                    std::sort(patchG.begin(),patchG.end());
                    std::sort(patchB.begin(),patchB.end());
                    switch (three) {
                    case 1:  //Median RGB
                        r = patchR.at(patchR.size()/2);
                        g = patchG.at(patchG.size()/2);
                        b = patchB.at(patchB.size()/2);
                        break;
                    case 2:  //Dilation RGB
                        r = patchR.at(patchR.size()-1);
                        g = patchG.at(patchG.size()-1);
                        b = patchB.at(patchB.size()-1);
                        break;
                    case 3:  //Erosion RGB
                        r = patchR.at(0);
                        g = patchG.at(0);
                        b = patchB.at(0);
                        break;
                    default:
                        break;
                    }
                    if (r>255)   r = 255;
                    if (g>255)   g = 255;
                    if (b>255)   b = 255;
                    if(r<0) r=0;
                    if(g<0) g=0;
                    if(b<0) b=0;
                    ret.setPixel(i,j, qRgb(r, g, b));
                }
            }
         }
    return ret;
}

std::vector<double> ImageProcessor::createBilateralKernel(double sigma)
{
    std::vector<double> ret;
    for(int i=0;i<256;i++)
        ret.push_back(exp((-i*i)/(2*sigma*sigma)));
    return ret;
}
QImage ImageProcessor::bilateralFilter(const QImage& img, int size,double sigmaSpace,double sigmaColor){
    //padding
    QImage padded = zeroPadding(img,size,size);

    //pre-calculate
    std::vector<double> kernelSpace = createGaussKernel(size,sigmaSpace);
    std::vector<double> kernelColor = createBilateralKernel(sigmaColor);

    //filter
    QImage filtered(padded);
    int width = padded.width();
    int height = padded.height();
    for(int i =size/2;i<width-size/2;++i){
        for(int j =size/2;j<height-size/2;++j){
            std::vector<int> patch = getPatch(padded,i,j,size,size,'y');
            std::vector<double> kernel;
            for(int k=0;k<kernelSpace.size();++k){
                int delta =abs(patch[k]-qGray(padded.pixel(i,j)));
                kernel.push_back(kernelColor[delta]*kernelSpace[k]);
            }
            kernelNormalization(kernel);
            double sum=0;
            for(int k=0;k<kernelSpace.size();++k){
                sum+= kernel[k]*patch[k];
            }
            int y =(int)sum;
            if(y>255) y = 255;
            filtered.setPixel(i,j,qRgb(y,y,y));
        }
    }
    // crop
    QImage croped = crop(filtered,size,size);
    return croped;
}
//------------------------------------------------------图像频谱图
//--------------------------------------------------------------

//         傅里叶变换代码

size_t ImageProcessor::calcN(size_t length) {
    // check if length is power of 2
    //return !(length&(length - 1));
    // if it is, just return length
    if(0==(length&(length - 1))){
        return length;
    }
    // if not, get the correct N and return
    size_t temp =length;
    while (temp>>=1){
        length |=temp;
    }
    return length+1;
}

vector<complex<double> > ImageProcessor::fft(vector<int> data, size_t N)
{
    // convert data to vector<complex<double> >
    // call:
    // vector<complex<double> >
    vector<complex<double> > ret;
    for (size_t i = 0; i < data.size(); i++) {
        complex<double> a(data[i], 0);
        ret.push_back(a);
    }
    return fft(ret, N);
    // fft(vector<complex<double> > data, size_t N)
}

vector<complex<double> > ImageProcessor::fft(vector<double> data, size_t N)
{
    // convert data to vector<complex<double> >
    // call:
    // vector<complex<double> >
    vector<complex<double> > ret;
    for (size_t i = 0; i < data.size(); i++) {
        complex<double> a(data[i], 0);
        ret.push_back(a);
    }
    return fft(ret, N);
    // fft(vector<complex<double> > data, size_t N)
}

complex<double> ImageProcessor::wnk(size_t N,int k){
    double PI = 3.1415926;
    double p = 2*PI*k/N;
    return complex<double>(cos(p),-1*sin(p));
}


vector<complex<double> > ImageProcessor::fft(vector<complex<double> > data, size_t N) {
    // start fft
    // check if N is 0, 1, 2
    // if N is 0 or 1, just return data
    N = calcN(N);
    while(N > data.size()){
        data.push_back((complex<double>(0.0 , 0.0)));
    }
    //cout<<"N=-----------------------"<<endl;
    //cout<<N<<endl;
    //cout<<"-----------------------"<<endl;
    vector<complex<double> > ret;
    if (N == 0 || N == 1) {
        return data;
    }
    // if N is 2, do dft on them
    else if (N == 2) {
        ret.push_back(ImageProcessor::wnk(2,0) * data[0] + ImageProcessor::wnk(2,0) * data[1]);
        ret.push_back(ImageProcessor::wnk(2,0) * data[0] + ImageProcessor::wnk(2,1) * data[1]);
        return ret;
    }
    // if N > 2, do fft
    else {
        //cout<<"-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-"<<endl;
        vector<complex<double> > odd, even;
        for (size_t i = 0; i<data.size(); i += 2) {
            even.push_back(data[i]);
            odd.push_back(data[i + 1]);
        }
        vector<complex<double> > evenRet = ImageProcessor::fft(even,N/2);
        vector<complex<double> > oddRet = ImageProcessor::fft(odd,N/2);

        for (int i = 0; i<N / 2; ++i) {
            ret.push_back(evenRet[i] + ImageProcessor::wnk(N,i) * oddRet[i]);
        }
        for (int i = 0; i<N / 2; ++i) {
            ret.push_back(evenRet[i] - ImageProcessor::wnk(N,i) * oddRet[i]);
        }
        return ret;
    }
}

Matrix<complex<double> > ImageProcessor::fft2d(const Matrix<int>& mat, size_t _nRow, size_t _nCol) {
    Matrix<std::complex<double> > ret(_nRow, _nCol, complex<double>(0.0));
    for (size_t i = 0; i < _nRow; i++) {
        for (size_t j = 0; j < _nCol; j++) {
            ret(i, j) = complex<double>(mat(i, j), 0);
        }
    }
    return fft2d(ret, _nRow, _nCol);
}


Matrix<complex<double> > ImageProcessor::fft2d(const Matrix<double>& mat, size_t _nRow, size_t _nCol) {
    Matrix<complex<double> > ret(_nRow, _nCol, 0);
    for (size_t i = 0; i < _nRow; i++) {
        for (size_t j = 0; j < _nCol; j++) {
            complex<double> a(mat(i, j), 0);
            ret(i, j) = a;
        }
    }
    return fft2d(ret, _nRow, _nCol);
}

Matrix<complex<double> > ImageProcessor::fft2d(const Matrix<complex<double> >& data, size_t M, size_t N) {

//---------------------------------------------
    size_t MM = calcN(M);
    size_t NN = calcN(N);
//---------------------------------------------
    // append 0
    Matrix<std::complex<double> > temp(MM, NN, complex<double>(0,0));
    cout<<"fft2d start to calculate(should be only one time)"<<endl;
    for (size_t i = 0; i<M; i++) {
        for (size_t j = 0; j<N; j++) {
             temp(i, j) = data(i, j);
        }
    }
    cout << " append zero finish " << endl;

    Matrix<std::complex<double> > temp2 = fftRow(temp,MM,NN).transpose();
    cout<<"first fftrow finish"<<endl;
    return fftRow(temp2,NN,MM).transpose();
}

Matrix<std::complex<double> > ImageProcessor::fftRow(const Matrix<std::complex<double> >& data,size_t nRow,size_t nCol){

    Matrix<std::complex<double> > ret(data);          //测试结果输出类似灰度图像的结果
    //Matrix<std::complex<double> > ret(Row,Col,complex<double>(0,0));    //测试结果输出全黑图像
    //Matrix<std::complex<double> > ret(Row,Col,complex<double>(50,100));    //测试结果输出全灰图像

    cout<<"one_time_fftRow_start"<<endl;

    for(size_t i =0;i<nRow;i++){
        ret.setRow(i,fft(data.getRow(i),nCol));
    }

    return ret;
}

Matrix<int> ImageProcessor::absandlog_guiyi(const Matrix<complex<double> >& vec){
    /*
    int max=0;
    int min=0;
    int a=0;
    int nCol = mat.getNCol();
    int nRow = mat.getNRow();
    Matrix<int> ret(nRow,nCol,0);
    for(int i=0;i<nRow;i++){
        for(int j=0;j<nCol;j++){
            //ret(i,j) = mat(i,j).real()*mat(i,j).real()+mat(i,j).imag()*mat(i,j).imag();
            //cout<<mat(i,j).real()<<endl;
            a = ret(i,j) = qLn(1 + qSqrt(mat(i,j).real()*mat(i,j).real()+mat(i,j).imag()*mat(i,j).imag()));

            (a>=max)?max=a:max=max;
            (a<=min)?min=a:min=min;
        }
    }
    cout<<"ti qu jve dui zhi"<<endl;
    int delta = max-min;
    for(int i=0;i<nRow;i++){
        for(int j=0;j<nCol;j++){
            ret(i,j) = (ret(i,j)-min) *255 /delta;
        }
    }
    cout<<"gui yi hua le ma "<<endl;
    return ret;
    */

    //取模
     int M = vec.getNRow();
     int N= vec.getNCol();
     Matrix<int> te(N, M, 0);
     for (size_t i = 0; i<M; i++) {
         for (size_t j = 0; j<N; j++) {
                te(j,i)=sqrt( vec(j, i).real()*vec(j,i).real() + vec(j, i).imag()*vec(j, i).imag() );
         }
     }
     //cout<<te<<endl;
     //cout<<"------------------------------------"<<endl;

    //log变换
     Matrix<double> te_(N, M, 0);
     for (size_t i = 0; i<M; i++) {
         for (size_t j = 0; j<N; j++) {
                te_(j,i)=log(1.0+ te(j,i));
         }
     }
     //cout<<te_<<endl;
     //cout<<"------------------------------------"<<endl;

     //fftshift
     Matrix<double> te__(N, M, 0);
     size_t _startM = (M/2 + M)% M;
     size_t _startN = (N/2 + N)% N;
     for (size_t i = 0; i<M; i++) {
         for (size_t j = 0; j<N; j++) {
                te__(j,i)=te_(_startN,_startM);
                _startN = (_startN +1) % N;
         }
          _startM = ( _startM +1) % M;
     }
     //cout<<te__<<endl;
     //cout<<"------------------------------------"<<endl;

     //归一化
     double t = 0.0;
     Matrix<int> te___(N, M, 0);
     for (size_t i = 0; i<M; i++) {
         for (size_t j = 0; j<N; j++) {

                if(te__(j,i)>t){
                t=te__(j,i);}
         }
     }
     for (size_t i = 0; i<M; i++) {
         for (size_t j = 0; j<N; j++) {
               te___(j,i)=( (te__(j,i))/(t) )*255;
         }
     }
     //cout<<te___<<endl;
     //cout<<"------------------------------------"<<endl;

return te___;



}

QImage ImageProcessor::fftQImage(QImage& mat){

    Matrix<int> MyMatrix = fromQImage(mat,'y');//QImage
    cout<<"ImgToMatrix finish"<<endl;

    Matrix<std::complex<double> > MyMatrixAfterfft = fft2d(MyMatrix,MyMatrix.getNRow(),MyMatrix.getNCol());
    cout<<"fft2dfinish"<<endl;

    Matrix<int> MyMatrixAfterguiyi = absandlog_guiyi(MyMatrixAfterfft);

    QImage ret = toQImage(MyMatrixAfterguiyi);

    return ret;
}

QImage ImageProcessor::fftLowPassFilterQImage(QImage& mat,double threshold){

    cout<<"This is lop filter"<<endl;
    Matrix<int> MyMatrix = fromQImage(mat,'y');//QImage
    cout<<"ImgToMatrix finish"<<endl;

    Matrix<std::complex<double> > MyMatrixAfterfft = fft2d(MyMatrix,MyMatrix.getNRow(),MyMatrix.getNCol());
    cout<<"fft2dfinish"<<endl;

    Matrix<int> MyMatrixAfterguiyi = absandlog_guiyi(MyMatrixAfterfft);

    Matrix<int> MyMatrixLowPassFilter = MatrixLowPassFilter(MyMatrixAfterguiyi,threshold);

    QImage ret = toQImage(MyMatrixLowPassFilter);

    return ret;
}

QImage ImageProcessor::fftHighPassFilterQImage(QImage& mat,double threshold){

    cout<<"This is hip filter"<<endl;
    Matrix<int> MyMatrix = fromQImage(mat,'y');//QImage
    cout<<"ImgToMatrix finish"<<endl;

    Matrix<std::complex<double> > MyMatrixAfterfft = fft2d(MyMatrix,MyMatrix.getNRow(),MyMatrix.getNCol());
    cout<<"fft2dfinish"<<endl;

    Matrix<int> MyMatrixAfterguiyi = absandlog_guiyi(MyMatrixAfterfft);

    Matrix<int> MyMatrixHighPassFilter = MatrixHighPassFilter(MyMatrixAfterguiyi,threshold);

    QImage ret = toQImage(MyMatrixHighPassFilter);

    return ret;
}

//-------------------------仿射变换-------------------------------------

QImage ImageProcessor::affineTransformMatrix(QImage& img,QMatrix& mat){

    double imgheight = img.height();
    double imgwidth = img.width();

    double MinX,MinY,MaxX,MaxY;
    ImageProcessor::getRange(mat,imgheight,imgwidth,MinX,MinY,MaxX,MaxY);// X=Width  Y=Height
    int newheight = floor(MaxY-MinY)+1;
    int newwidth = floor(MaxX-MinX)+1;

    cout<<"-------imgheight-------"<<endl;
    cout<<imgheight<<endl;
    cout<<"-------imgwidth-------"<<endl;
    cout<<imgwidth<<endl;
    cout<<"-------MinX-------"<<endl;
    cout<<MinX<<endl;
    cout<<"-------MinY-------"<<endl;
    cout<<MinY<<endl;
    cout<<"-------MaxX-------"<<endl;
    cout<<MaxX<<endl;
    cout<<"-------MaxY-------"<<endl;
    cout<<MaxY<<endl;
    cout<<"-------newheight-------"<<endl;
    cout<<newheight<<endl;
    cout<<"-------newwidth-------"<<endl;
    cout<<newwidth<<endl;

    QImage newimg(newwidth,newheight,img.format());//应该加1
    for(int i = 0;i<newwidth;i++){
        for(int j = 0;j<newheight;j++){
            QRgb newcolor = ImageProcessor::getColor(img,mat,i,j,MinX,MinY);
            newimg.setPixel(i,j,newcolor);
        }
    }
    return newimg;
}

void ImageProcessor::getRange(QMatrix& mat,double height,double width,double& MinX,double& MinY,double& MaxX,double& MaxY){
    vector<qreal> realx(4),realy(4);

    mat.map(0,0,             &realx[0],&realy[0]);//left up
    mat.map(0,height-1,      &realx[1],&realy[1]);//left down
    mat.map(width-1,0,       &realx[2],&realy[2]);//right up
    mat.map(width-1,height-1,&realx[3],&realy[3]);//right down

    MinX = std::min(std::min(realx[0],realx[1]),std::min(realx[2],realx[3]));
    MinY = std::min(std::min(realy[0],realy[1]),std::min(realy[2],realy[3]));
    MaxX = std::max(std::max(realx[0],realx[1]),std::max(realx[2],realx[3]));
    MaxY = std::max(std::max(realy[0],realy[1]),std::max(realy[2],realy[3]));

}

QRgb ImageProcessor::getColor(QImage& img,QMatrix& mat,int i,int j,double MinX,double MinY){
    QMatrix invertmat = mat.inverted();
    double originX,originY;
    invertmat.map(i+MinX,j+MinY,&originX,&originY);
    if(originX<0||originX>img.width()-1||originY<0||originY>img.height()-1){
        return qRgb(0,0,0);
    }
    else{
        QRgb color = ImageProcessor::bilinear(img,originX,originY);
        return color;
    }

}
QRgb ImageProcessor::bilinear(QImage& img,double originX,double originY){
    //找到四个点
    int x1 = floor(originX)+1;
    int x2 = floor(originX);
    int y1 = floor(originY)+1;
    int y2 = floor(originY);

    QRgb rgb1 = img.pixel(x1,y1);
    QRgb rgb2 = img.pixel(x1,y2);
    QRgb rgb3 = img.pixel(x2,y1);
    QRgb rgb4 = img.pixel(x2,y2);

    //red
    double temp1,temp2;
    temp1 = ImageProcessor::bilinear_cal(qRed(rgb1),qRed(rgb2),y1,y2,originY);
    temp2 = ImageProcessor::bilinear_cal(qRed(rgb3),qRed(rgb4),y1,y2,originY);
    double red = ImageProcessor::bilinear_cal(temp1,temp2,x1,x2,originX);
    //green
    temp1 = ImageProcessor::bilinear_cal(qGreen(rgb1),qGreen(rgb2),y1,y2,originY);
    temp2 = ImageProcessor::bilinear_cal(qGreen(rgb3),qGreen(rgb4),y1,y2,originY);
    double green = ImageProcessor::bilinear_cal(temp1,temp2,x1,x2,originX);
    //blue
    temp1 = ImageProcessor::bilinear_cal(qBlue(rgb1),qBlue(rgb2),y1,y2,originY);
    temp2 = ImageProcessor::bilinear_cal(qBlue(rgb3),qBlue(rgb4),y1,y2,originY);
    double blue = ImageProcessor::bilinear_cal(temp1,temp2,x1,x2,originX);
    return qRgb(red,green,blue);
}
double ImageProcessor::bilinear_cal(double v1,double v2,double c1,double c2,double c3){
    if(c1==c2){
        return v1;
    }
    else{
        return (c2-c3)/(c2-c1)*v1+(c3-c1)/(c2-c1)*v2;
    }
}

//--------------------------------仿射变换结束--------------------------------





//--------------------------------图像颜色处理开始--------------------------------

QImage ImageProcessor::RGBToGray(const QImage& img){
      QImage ret(img);
      int width = img.width();
      int height = img.height();
      for(int i=0;i<width;++i){
          for(int j=0;j<height;++j){
              QRgb rgb= img.pixel(i,j);
              int r = qRed(rgb);
              int g = qGreen(rgb);
              int b = qBlue(rgb);
              int gray = (r+g+b)/3;
              ret.setPixel(i,j,qRgb(gray,gray,gray));
          }
      }
      return ret;
}
QImage ImageProcessor::ImageReversal(const QImage& img){
   QImage ret(img);
   int width = img.width();
   int height = img.height();
   for(int i=0;i<width;++i){
       for(int j=0;j<height;++j){
           QRgb rgb=img.pixel(i,j);
           int r=255-qRed(rgb);
           int g=255-qGreen(rgb);
           int b=255-qBlue(rgb);
           ret.setPixel(i,j,qRgb(r,g,b));
       }
   }
   return ret;
}

QImage ImageProcessor::LogTransform(const QImage& img, double c){
   QImage ret = RGBToGray(img);
   int width = img.width();
   int height = img.height();
   for(int i=0;i<width;i++){
       for(int j=0;j<height;j++){
           int g = qRed(ret.pixel(i,j));
           int ng = (c*log(1+g/255.0))*255;
           if(ng>255) ng=255;
           ret.setPixel(i,j,qRgb(ng,ng,ng));
       }
   }
   return ret;
}

QImage ImageProcessor::GrayToHist(const QImage &img){
   QImage ret(img);
   int width = img.width();
   int height = img.height();
   int N = width*height;

   int hist[256];
   std::fill(hist,hist+256,0);
   for(int i=0;i<width;i++)
       for(int j=0;j<height;j++)
           hist[qGray(img.pixel(i,j))]++;

   int map[256];
   double sum=0;
   for(int i =0;i<256;i++){
       sum+=hist[i];
       map[i] = round(sum/N*255);
   }
   for(int i=0;i<width;i++){
       for(int j=0;j<height;j++){
           int g = map[qGray(img.pixel(i,j))];
           ret.setPixel(i,j,qRgb(g,g,g));
       }
   }
   return ret;
}

QImage ImageProcessor::RGBToHist(const QImage &img){
   QImage ret(img);
   int width = img.width();
   int height = img.height();
   int N = width*height;

   int hist[3][256];
   std::fill(hist[0],hist[0]+3*256,0);
   for(int i=0;i<width;i++)
       for(int j=0;j<height;j++){
           hist[0][qRed(img.pixel(i,j))]++;
           hist[1][qGreen(img.pixel(i,j))]++;
           hist[2][qBlue(img.pixel(i,j))]++;
       }
   int map[3][256];
   double sumR=0;
   double sumG=0;
   double sumB=0;
   for(int i =0;i<256;i++){
       sumR+=hist[0][i];
       map[0][i] = round(sumR/N*255);
       sumG+=hist[1][i];
       map[1][i] = round(sumG/N*255);
       sumB+=hist[2][i];
       map[2][i] = round(sumB/N*255);
   }
   for(int i=0;i<width;i++){
       for(int j=0;j<height;j++){
           int r = map[0][qRed(img.pixel(i,j))];
           int g = map[1][qGreen(img.pixel(i,j))];
           int b = map[2][qBlue(img.pixel(i,j))];
           ret.setPixel(i,j,qRgb(r,g,b));
       }
   }
   return ret;
}
QImage ImageProcessor::RGBToHSI(const QImage& img){
   QImage ret(img);
   int width = img.width();
   int height = img.height();
   int N = width*height;

   //RGB 2 HSI
   HSI *Hsi = new HSI[N];
   for(int i=0;i<width;i++)
       for(int j =0;j<height;j++){
           QRgb rgb = ret.pixel(i,j);
           Hsi[i*height+j] = HSI();
           rgb2hsi(rgb,Hsi[i*height+j]);
       }

   //count histogram of I
   int hist[256];
   std::fill(hist,hist+256,0);
   for(int i=0;i<N;i++)
       hist[int((Hsi[i].i)*255)]++;

   //calcumate map function
   int map[256];
   double sum=0;
   for(int i =0;i<256;i++){
       sum+=hist[i];
       map[i] = round(sum/N*255);
   }

   //map the pixel
   for(int i=0;i<N;i++){
       Hsi[i].i = map[int((Hsi[i].i)*255)];}
   for(int i=0;i<N;i++){
       Hsi[i].i = 1.0*Hsi[i].i/255;}

   //HSI to RGB
   for(int i=0;i<width;i++)
       for(int j=0;j<height;j++){
           int r,g,b;
           hsi2rgb(Hsi[i*height+j],r,g,b);
           ret.setPixel(i,j,qRgb(r,g,b));
       }
   return ret;

}
//观察一下的三个方法，虽然是在Image中为RGBToHSI服务的，但是并没有用到QImage，所以这里不做修改，直接在MatrixRGBToHSI中引用这里的方法
void ImageProcessor::hsi2rgb(HSI hsi, int& r, int& g, int& b){
   double var_2;

   if(hsi.s==0){
       r=hsi.i*255;
       g=hsi.i*255;
       b=hsi.i*255;
   }
   else{
       if(hsi.i<0.5) {var_2=hsi.i*(1+hsi.s); }
       else          {var_2=(hsi.i+hsi.s)-(hsi.s*hsi.i); }

       double var_1 = 2*hsi.i-var_2;
       double onethree=1.0*1/3;
       r = 255*Hue_2_RGB(var_1,var_2,hsi.h+onethree);
       g = 255*Hue_2_RGB(var_1,var_2,hsi.h);
       b = 255*Hue_2_RGB(var_1,var_2,hsi.h-onethree);

   }
}
double ImageProcessor::Hue_2_RGB(double v1, double v2, double vh){
   if(vh<0)vh+=1;
   if(vh>0)vh-=1;
   double twothree=1.0*2/3;
   if((6*vh)<1) return(v1+(v2-v1)*vh*6);
   if((2*vh)<1) return(v2);
   if((3*vh)<2) return(v1+(v2-v1)*(twothree-vh)*6);
   return (v1);
}

void ImageProcessor::rgb2hsi(QRgb rgb, HSI& hsi){
   double r =qRed(rgb);
   double g =qGreen(rgb);
   double b =qBlue(rgb);

   double var_r=(1.0*r/255);
   double var_g=(1.0*g/255);
   double var_b=(1.0*b/255);
   double maxnumber =std::max(std::max(var_r,var_g),var_b);
   double minnumber =std::min(std::min(var_r,var_g),var_b);
   double delta = maxnumber-minnumber;
   hsi.i = 1.0*(maxnumber+minnumber)/2;
   if(delta==0){
       hsi.h=0;
       hsi.s=0;
       }
   else{
       if(hsi.i<0.5) {hsi.s = 1.0*delta/(maxnumber+minnumber);}
       else          {hsi.s = 1.0*delta/(2-maxnumber-minnumber);}
   double del_r = (((1.0*maxnumber-var_r)/6)+(1.0*delta/2))/delta;
   double del_g = (((1.0*maxnumber-var_g)/6)+(1.0*delta/2))/delta;
   double del_b = (((1.0*maxnumber-var_b)/6)+(1.0*delta/2))/delta;
   if     (var_r==maxnumber)   hsi.h = del_b-del_g;
   else if(var_g==maxnumber)   hsi.h = (1.0*1/3)+del_r-del_b;
   else if(var_b==maxnumber)   hsi.h = (1.0*2/3)+del_g-del_r;

   if(hsi.h<0) hsi.h+=1;
   if(hsi.h>1) hsi.h-=1;}
}
//--------------------------------图像颜色处理结束--------------------------------

//-----------------------------图像滤波器处理---------------------

