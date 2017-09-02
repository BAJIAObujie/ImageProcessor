#ifndef MATRIX__H
#define MATRIX__H

#include <complex>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <QImage>
#include "imageprocessor.h"

using std::complex;
using std::vector;
using namespace std;

template<typename T>
class Matrix
{
private:
	// point to the data
	T** _data;
	// number of row and column
	size_t _nRow, _nCol;
	// flag to indicate row-first or column-first
	int _t;
	bool checkRange(size_t r, size_t c) const;
	void swap(Matrix<T>& mat);



public:
	// construct a r-row and c-column matrix with all init element
	Matrix(size_t r, size_t c, T init);
	// copy constructor
	Matrix(const Matrix<T>& mat);
	Matrix& operator=(Matrix<T> mat);
	~Matrix();
	// get element at r-row and c-column
	// return reference to make it modifiable
	T& operator()(size_t r, size_t c) const;
	// get a submatrix [rs:re,cs:ce]
	Matrix subMatrix(size_t rs, size_t re, size_t cs, size_t ce) const;
	// output the matrix
	template<typename U>
	friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& rhs);
	size_t getNRow() const;
	size_t getNCol() const;
	std::vector<T> getRow(size_t r) const;
	std::vector<T> getCol(size_t c) const;
	bool setRow(size_t r, const std::vector<T>& d);
	bool setCol(size_t c, const std::vector<T>& d);
	// transpose it in-place
	Matrix<T>& transpose();

	//add
	
	Matrix<T> operator+(T);
	template<typename U>
	friend Matrix<U> operator+(U,  Matrix<U>& rhs);
	template<typename U>
	friend Matrix<U> operator+(Matrix<U>&lhs, Matrix<U>& rhs);
	//friend Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs);

	
	//substract
	Matrix<T> operator-(T);
	template<typename U>
	friend Matrix<U> operator-(U, Matrix<U>& rhs);
	template<typename U>
	friend Matrix<U> operator-(Matrix<U>&lhs, Matrix<U>& rhs);


	//multiply
	Matrix<T> operator*(T);
	template<typename U>
	friend Matrix<U> operator*(U, Matrix<U>& rhs);
	template<typename U>
	friend Matrix<U> operator*(Matrix<U>&lhs, Matrix<U>& rhs);
	//devide
	Matrix<T> operator/(T);
	

};

template<typename T>
Matrix<T> Matrix<T>::subMatrix(size_t rs, size_t re, size_t cs, size_t ce) const
{
	size_t sub_x = re - rs + 1;
	size_t sub_y = ce - cs + 1;
	// note the validity of value:rs, re, cs, ce
	if (checkRange(rs, cs) && checkRange(re, ce) && sub_x>0 && sub_y>0) {
		Matrix sub(sub_x, sub_y, 0.0);
		for (size_t i = 0; i < sub_x; i++) {
			for (size_t j = 0; j < sub_y; j++) {
				sub._data[i][j] = _data[rs + i][cs + j];
			}
		}
		return sub;
	}
	else {
		throw range_error("subMatrix: out of range");
	}
	// try to use "except" to broadcast the exception
}

template<typename T>
Matrix<T>::Matrix(size_t r, size_t c, T init):
_nRow(r), _nCol(c), _t(0)
{
	_data = new T*[_nRow];
	for (size_t i = 0; i < _nRow; i++) {
		_data[i] = new T[_nCol];
		for (size_t j = 0; j < _nCol; j++) {
			_data[i][j] = init;
		}
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& mat):
_nRow(mat._nRow), _nCol(mat._nCol), _t(mat._t)
{
    if (_t == 0){
        _data = new T*[_nRow];
        for (size_t i = 0; i < _nRow; i++) {
            _data[i] = new T[_nCol];
            for (size_t j = 0; j < _nCol; j++) {
                _data[i][j] = mat._data[i][j];
            }
        }
    }
    else{
        _data = new T*[_nCol];
        for (size_t i = 0; i < _nCol; i++) {
            _data[i] = new T[_nRow];
            for (size_t j = 0; j < _nRow; j++) {
                _data[i][j] = mat._data[i][j];
            }
        }
    }

}

template<typename T>
void Matrix<T>::swap(Matrix<T>& mat) {
    std::swap(_data, mat._data);
	std::swap(_nRow, mat._nRow);
	std::swap(_nCol, mat._nCol);
    std::swap(_t, mat._t);
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T> mat)
{
	swap(mat);
	return *this;
}

template<typename T>
size_t Matrix<T>::getNRow() const
{
	return _nRow;
}

template<typename T>
size_t Matrix<T>::getNCol() const
{
	return _nCol;
}

template<typename T>
bool Matrix<T>::checkRange(size_t r, size_t c) const
{
	if (r >= _nRow || c >= _nCol || r < 0 || c < 0) {
		cout << "checkRange : out of range" << endl;
		return false;
	}
	else {
		return true;
	}
}

template<typename T>
T& Matrix<T>::operator()(size_t r, size_t c) const
{
	if (checkRange(r, c)) {
		if (_t == 0)
		{
			return _data[r][c];
		}
		else
		{
			return _data[c][r];
		}
	}
	else {
		throw range_error("operator error");
	}
}

template<typename T>
std::vector<T> Matrix<T>::getRow(size_t r) const
{
	if (checkRange(r, 0)) {
		if (_t == 0) {
			std::vector<T> ret;
			for (size_t i = 0; i < _nRow; i++) {
				ret.push_back(_data[r][i]);
			}
			return ret;
		}
		else {
			std::vector<T> ret;
			for (size_t i = 0; i < _nCol; i++) {
				ret.push_back(_data[i][r]);
			}
			return ret;
		}
	}
	else {
		throw range_error("getRow: out of range");
	}
}

template<typename T>
std::vector<T> Matrix<T>::getCol(size_t c) const
{
	if (checkRange(0, c)) {
		if (_t == 0) {
			std::vector<T> ret;
			for (size_t i = 0; i < _nCol; i++) {
				ret.push_back(_data[i][c]);
			}
			return ret;
		}
		else {
			std::vector<T> ret;
			for (size_t i = 0; i < _nRow; i++) {
				ret.push_back(_data[c][i]);
			}
			return ret;
		}
	}
	else {
		throw range_error("getCol: out of range");
	}
}

template<typename T>
bool Matrix<T>::setRow(size_t r, const std::vector<T>& d)
{
	size_t x = d.size();
	if (checkRange(r, 0) && _nCol == x) {
		for (size_t i = 0; i < _nCol; i++) {
			_data[r][i] = d[i];
			return true;
		}
	}
	else {
		cout << "r is out of range" << endl;
		return false;
	}
}

template<typename T>
bool Matrix<T>::setCol(size_t c, const std::vector<T>& d)
{
	size_t x = d.size();
	if (checkRange(0, c) && _nRow == x) {
		for (size_t i = 0; i <_nRow; i++) {
			_data[i][c] = d[i];
			//cout << _data[i][c] << endl;
		}
		return true;
	}
	else {
		cout << "c is out of range" << endl;
		return false;
	}
}

template<typename T>
Matrix<T>::~Matrix()
{
	if (_t == 0) {
		for (size_t i = 0; i<_nRow; i++)
		{
			delete[] _data[i];
		}
		delete[] _data;
	}
	else {
		for (size_t i = 0; i<_nCol; i++)
		{
			delete[] _data[i];
		}
		delete[] _data;
	}
}

template<typename T>
Matrix<T>& Matrix<T>::transpose()
{
	_t = !_t;
    std::swap(_nRow, _nCol);
	return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& rhs)
{
	
	for(size_t i=0; i<rhs._nRow; ++i) {
		for(size_t j=0; j<rhs._nCol; ++j) {
			out << rhs(i,j) << "\t";
		}
		out << endl;
	}
	return out;
	
}


template<typename T>
Matrix<T> Matrix<T>::operator+(T add_number) {
	
	Matrix<T> ret(_nRow, _nCol, 0);
	for (size_t i = 0; i < _nRow; i++) {
		for (size_t j = 0; j < _nCol; j++) {
			ret._data[i][j] = _data[i][j] + add_number;
		}
	}
	return ret;
}
template<typename U>
Matrix<U> operator+(U num,  Matrix<U>& rhs) {
	//return rhs + T;
	return rhs.operator+(num);
}

template<typename U>
Matrix<U> operator+(Matrix<U>& lhs, Matrix<U>& rhs) {
	if (lhs._nCol == rhs._nCol && lhs._nRow == rhs._nRow) {
		Matrix<U> ret(lhs._nRow, lhs._nCol, 0.0);
		for (size_t i = 0; i < lhs._nRow; i++) {
			for (size_t j = 0; j < lhs._nCol; j++) {
				ret._data[i][j] = lhs._data[i][j] + rhs._data[i][j];
			}
		}
		return ret;
	}
	else {
		throw range_error("Matrixs has different Cols or Rows");
	}
}

template<typename T>
Matrix<T> Matrix<T>::operator-(T minus_number) {
	Matrix<T> ret(_nRow, _nCol, 0);
	for (size_t i = 0; i < _nRow; i++) {
		for (size_t j = 0; j < _nCol; j++) {
			ret._data[i][j] = _data[i][j] - minus_number;
		}
	}
	return ret;
}
template<typename U>
Matrix<U> operator-(U num, Matrix<U>& rhs) {
	//return rhs.operator-(num);
	Matrix<U> ret(rhs._nRow, rhs._nCol, 0);
	Matrix<U> number(rhs._nRow, rhs._nCol, num);
	for (size_t i = 0; i < rhs._nRow; i++) {
		for (size_t j = 0; j < rhs._nCol; j++) {
			ret(i,j) = number(i,j) - rhs(i,j);
		}
	}
	return ret;
}
template<typename U>
Matrix<U> operator-(Matrix<U>& lhs, Matrix<U>& rhs) {
	if (lhs._nCol == rhs._nCol && lhs._nRow == rhs._nRow) {
		Matrix<U> ret(lhs._nRow, lhs._nCol, 0.0);
		for (size_t i = 0; i < lhs._nRow; i++) {
	    //for (size_t i = 0; i < lhs.getRow(lhs._t); i++) {
			for (size_t j = 0; j < lhs._nCol; j++) {
				ret._data[i][j] = lhs._data[i][j] - rhs._data[i][j];
			}
		}
		return ret;
	}
	else {
		throw range_error("Matrixs has different Cols or Rows");
	}
}



template<typename T>
Matrix<T> Matrix<T>::operator*(T multiplier) {
	Matrix<T> ret(_nRow, _nCol, 0);
	for (size_t i = 0; i < _nRow; i++) {
		for (size_t j = 0; j < _nCol; j++) {
			ret._data[i][j] = _data[i][j] * multiplier;
		}
	}
	return ret;
}

template<typename U>
Matrix<U> operator*(U num, Matrix<U>& rhs) {
	return rhs.operator*(num);
}
template<typename U>
Matrix<U> operator*(Matrix<U>& lhs, Matrix<U>& rhs) {
	if (lhs.getNCol() == rhs.getNRow()) {
		Matrix<U> ret(lhs.getNRow(), rhs.getNCol(), 0.0);
		for (size_t i = 0; i < lhs.getNRow(); i++) {
			for (size_t j = 0; j < rhs.getNCol(); j++) {
				for (size_t time = 0; time < lhs.getNCol(); time++) {
					ret(i,j) += lhs(i,time) * rhs(time,j);
				}
			}
		}
		return ret;
	}
	else {
		throw range_error("Matrixs has different Cols or Rows");
	}
}

template<typename T>
Matrix<T> Matrix<T>::operator/(T division) {
	Matrix<T> ret(_nRow, _nCol, 0);
	for (size_t i = 0; i < _nRow; i++) {
		for (size_t j = 0; j < _nCol; j++) {
			ret._data[i][j] = _data[i][j] / division;
		}
	}
	return ret;
}

//--------------------------图像频谱------------------------

static Matrix<int> fromQImage(const QImage& mat, char a){
    //form = mat.format();
    int nCol = mat.width();
    int nRow = mat.height();
    Matrix<int> ret(nRow,nCol,0);
    for(int i=0;i<nRow;i++){
        for(int j=0;j<nCol;j++){
            switch (a) {
            case 'r':
                ret(i,j) = qRed(mat.pixel(j,i));
                break;
            case 'g':
                ret(i,j) = qGreen(mat.pixel(j,i));
                break;
            case 'b':
                ret(i,j) = qBlue(mat.pixel(j,i));
                break;
            case 'y':
                ret(i,j) = qGray(mat.pixel(j,i));
                break;
            default:
                break;
            }
        }
    }
    return ret;
}

static QImage toQImage(const Matrix<int>& gray){
    int nCol = gray.getNCol();
    int nRow = gray.getNRow();
    //QImage ret(nRow,nCol,form);
    QImage ret(nCol,nRow,QImage::Format_RGB32);
    for(int i=0;i<nRow;i++){
        for(int j=0;j<nCol;j++){
            ret.setPixel(j,i, qRgb(gray(i,j), gray(i,j), gray(i,j)));
            //ret.setPixel(i,j, qRgb(gray(i,j), gray(i,j), gray(i,j)));
        }
    }
    cout<<"zhuan hua dao QImage"<<endl;
    return ret;
}
static QImage toQImage(const Matrix<int>& red,const Matrix<int>& green,const Matrix<int>& blue){
    int nCol = red.getNCol();
    int nRow = red.getNRow();
    //QImage::Format form;
    QImage ret(nRow,nCol,QImage::Format_RGB32);
    //QImage ret(nRow,nCol,form);
    for(int i=0;i<nRow;i++){
        for(int j=0;j<nCol;j++){
            ret.setPixel(j,i, qRgb(red(j,i), green(j,i), blue(j,i)));
            //ret.setPixel(i,j, qRgb(red(i,j), green(i,j), blue(i,j)));
        }
    }
    return ret;
}

//--------------------------图像频谱结束------------------------

//--------------------------图像颜色处理------------------------
//第一个灰度OK
static QImage MatrixRGBToGray(const QImage& img){

      QImage ret(img);
      Matrix<int> MyMatrixRed = fromQImage(ret,'r');
      Matrix<int> MyMatrixGreen = fromQImage(ret,'g');
      Matrix<int> MyMatrixBlue = fromQImage(ret,'b');
      int width = MyMatrixRed.getNCol();
      int height = MyMatrixRed.getNRow();
      for(int i=0;i<width;++i){
          for(int j=0;j<height;++j){
              int r= MyMatrixRed(j,i);
              int g= MyMatrixGreen(j,i);
              int b= MyMatrixBlue(j,i);
              int gray = (r+g+b)/3;
              ret.setPixel(i,j,qRgb(gray,gray,gray));
          }
      }
      return ret;
}
//第二个图像反转OK
static QImage MatrixImageReversal(const QImage& img){

    QImage ret(img);
    Matrix<int> MyMatrixRed = fromQImage(ret,'r');
    Matrix<int> MyMatrixGreen = fromQImage(ret,'g');
    Matrix<int> MyMatrixBlue = fromQImage(ret,'b');
    int width = MyMatrixRed.getNCol();
    int height = MyMatrixRed.getNRow();
    for(int i=0;i<width;++i){
        for(int j=0;j<height;++j){
            int r= 255-MyMatrixRed(j,i);
            int g= 255-MyMatrixGreen(j,i);
            int b= 255-MyMatrixBlue(j,i);
            ret.setPixel(i,j,qRgb(r,g,b));
        }
    }
    return ret;
}

//第三个对数变换OK
static QImage MatrixLogTransform(const QImage& img, double c){
    QImage ret(img);
    Matrix<int> MyMatrixGray = fromQImage(img,'y');
    int width = MyMatrixGray.getNCol();
    int height = MyMatrixGray.getNRow();
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            int g = MyMatrixGray(j,i);
            int ng = (c*log(1+g/255.0))*255;
            if(ng>255) ng=255;
            ret.setPixel(i,j,qRgb(ng,ng,ng));
        }
    }
    return ret;
}

//第四个灰度直方图均衡变换
static QImage MatrixGrayToHist(const QImage &img){
   QImage ret(img);
   Matrix<int> MyMatrixGray = fromQImage(img,'y');
   int width = MyMatrixGray.getNCol();
   int height = MyMatrixGray.getNRow();
   int N = width*height;

   int hist[256];
   std::fill(hist,hist+256,0);
   for(int i=0;i<width;i++)
       for(int j=0;j<height;j++)
           hist[MyMatrixGray(j,i)]++;

   int map[256];
   double sum=0;
   for(int i =0;i<256;i++){
       sum+=hist[i];
       map[i] = round(sum/N*255);
   }
   for(int i=0;i<width;i++){
       for(int j=0;j<height;j++){
           int g = map[MyMatrixGray(j,i)];
           ret.setPixel(i,j,qRgb(g,g,g));
       }
   }
   return ret;
}

static QImage MatrixRGBToHist(const QImage &img){
    QImage ret(img);
    Matrix<int> MyMatrixRed = fromQImage(ret,'r');
    Matrix<int> MyMatrixGreen = fromQImage(ret,'g');
    Matrix<int> MyMatrixBlue = fromQImage(ret,'b');
    int width = MyMatrixRed.getNCol();
    int height = MyMatrixRed.getNRow();
   int N = width*height;

   int hist[3][256];
   std::fill(hist[0],hist[0]+3*256,0);
   for(int i=0;i<width;i++)
       for(int j=0;j<height;j++){
           hist[0][MyMatrixRed(j,i)]++;
           hist[1][MyMatrixGreen(j,i)]++;
           hist[2][MyMatrixBlue(j,i)]++;
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
           int r = map[0][MyMatrixRed(j,i)];
           int g = map[1][MyMatrixGreen(j,i)];
           int b = map[2][MyMatrixBlue(j,i)];
           ret.setPixel(i,j,qRgb(r,g,b));
       }
   }
   return ret;
}
//尚未修改，因为原来图像转HSI就有问题，看看能不能修改过来在改成矩阵。
/*
static QImage MatrixRGBToHSI(const QImage& img){
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
*/
//--------------------------图像颜色处理到此结束----------------------

//--------------------------图像滤波器部分开始
//-------补零
static QImage MatrixzeroPadding(const QImage& img, int nCol, int nRow)
{
    QImage ret(img.width()+nCol-1, img.height()+nRow-1, img.format());
    Matrix<int> MyMatrixRed = fromQImage(img,'r');
    Matrix<int> MyMatrixGreen = fromQImage(img,'g');
    Matrix<int> MyMatrixBlue = fromQImage(img,'b');
    int width = MyMatrixRed.getNCol();
    int height = MyMatrixRed.getNRow();

    for(int i=0; i<width; ++i)
    {
        for(int j=0; j<height; ++j)
        {
            if(i<nCol/2 || i>=width-nCol/2 ||
                    j<nRow/2 || j>=height-nRow/2)
                ret.setPixel(i, j ,qRgb(0,0,0));
            else{
                int r = MyMatrixRed(j-nRow/2,i-nCol/2);
                int g = MyMatrixGreen(j-nRow/2,i-nCol/2);
                int b = MyMatrixBlue(j-nRow/2,i-nCol/2);
                ret.setPixel(i, j, qRgb(r,g,b));
            }
        }
    }
    return ret;
}

//-------------------线性滤波器
static std::vector<int> MatrixgetPatch(const Matrix<int>& MyMatrix, int w, int h, int nCol, int nRow)
{
    std::vector<int> ret;
    for(int i=w-nCol/2; i<=w+nCol/2; ++i)
    {
        for(int j=h-nRow/2; j<=h+nRow/2; ++j)
        {
            ret.push_back(MyMatrix(j,i));
        }
    }
    return ret;
}

static QImage Matrixfilter(const QImage& img, std::vector<double> kernel, int nCol, int nRow,bool isgray)
{
    QImage ret(img);
    Matrix<int> MyMatrixRed = fromQImage(ret,'r');
    Matrix<int> MyMatrixGreen = fromQImage(ret,'g');
    Matrix<int> MyMatrixBlue = fromQImage(ret,'b');
    Matrix<int> MyMatrixGray = fromQImage(ret,'y');
    int width = MyMatrixRed.getNCol();
    int height = MyMatrixRed.getNRow();

    for(int i=nCol/2; i<width-nCol/2; ++i)
    {
        for(int j=nRow/2; j<height-nRow/2; ++j)
        {
            if(isgray){
                std::vector<int> patchY = MatrixgetPatch(MyMatrixGray, i,j,  nCol, nRow);
                double sumY = 0;
                for(int k=0; k<kernel.size(); ++k)
                    sumY += kernel[k]*patchY[k];
                int y = (int)sumY;
                if (y>255)   y = 255;
                if(y<0) y=0;
                ret.setPixel(i,j, qRgb(y,y,y));
            }
            else{
                std::vector<int> patchR = MatrixgetPatch(MyMatrixRed, i, j, nCol, nRow);
                std::vector<int> patchG = MatrixgetPatch(MyMatrixGreen, i, j, nCol, nRow);
                std::vector<int> patchB = MatrixgetPatch(MyMatrixBlue, i, j, nCol, nRow);
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

static QImage Matrixcrop(const QImage& img, int nCol, int nRow)
{
    QImage ret(img.width()-nCol+1, img.height()-nRow+1, img.format());
    Matrix<int> MyMatrixRed = fromQImage(img,'r');
    Matrix<int> MyMatrixGreen = fromQImage(img,'g');
    Matrix<int> MyMatrixBlue = fromQImage(img,'b');
    int width = ret.width();
    int height = ret.height();
    for(int i=0; i<width; ++i)
    {
        for(int j=0; j<height; ++j)
        {
            int r = MyMatrixRed(j+nRow/2, i+nCol/2);
            int g = MyMatrixGreen(j+nRow/2, i+nCol/2);
            int b = MyMatrixBlue(j+nRow/2, i+nCol/2);
            ret.setPixel(i, j, qRgb(r,g,b));
        }
    }
    return ret;
}

//高斯滤波和线性滤波一样,不同在于用输入的参数做一个权值的vector，然后用来与图片中相应的像素，也就是矩阵中的点相乘得出结果。

//中值滤波如下

static QImage Matrixmedianfilter(const QImage& img, int size,bool isgray,int three){
    QImage ret(img);

    Matrix<int> MyMatrixRed = fromQImage(ret,'r');
    Matrix<int> MyMatrixGreen = fromQImage(ret,'g');
    Matrix<int> MyMatrixBlue = fromQImage(ret,'b');
    Matrix<int> MyMatrixGray = fromQImage(ret,'y');
    int width = MyMatrixRed.getNCol();
    int height = MyMatrixRed.getNRow();

    int r,g,b,y;
    //gray
    if(isgray){
            for(int i=size/2; i<width-size/2; ++i)
            {
                for(int j=size/2; j<height-size/2; ++j)
                {
                    std::vector<int> patchY = MatrixgetPatch(MyMatrixGray, i, j, size, size);
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
    //not gray
    else{
            for(int i=size/2; i<width-size/2; ++i)
            {
                for(int j=size/2; j<height-size/2; ++j)
                {
                    std::vector<int> patchR = MatrixgetPatch(MyMatrixRed, i, j, size, size);
                    std::vector<int> patchG = MatrixgetPatch(MyMatrixGreen, i, j, size, size);
                    std::vector<int> patchB = MatrixgetPatch(MyMatrixBlue, i, j, size, size);

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

static std::vector<double> createGaussKernel(int size,double sigma){
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
static std::vector<double> createBilateralKernel(double sigma)
{
    std::vector<double> ret;
    for(int i=0;i<256;i++)
        ret.push_back(exp((-i*i)/(2*sigma*sigma)));
    return ret;
}
static void kernelNormalization(std::vector<double>& kernel)
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
static QImage MatrixbilateralFilter(const QImage& img, int size,double sigmaSpace,double sigmaColor){
    //padding
    QImage padded = MatrixzeroPadding(img,size,size);

    //pre-calculate
    std::vector<double> kernelSpace = createGaussKernel(size,sigmaSpace);
    std::vector<double> kernelColor = createBilateralKernel(sigmaColor);

    //filter
    QImage filtered(padded);
    Matrix<int> MyMatrixGray = fromQImage(filtered,'y');

    int width = MyMatrixGray.getNCol();
    int height =MyMatrixGray.getNRow();

    for(int i =size/2;i<width-size/2;++i){
        for(int j =size/2;j<height-size/2;++j){
            std::vector<int> patch = MatrixgetPatch(MyMatrixGray,i,j,size,size);
            std::vector<double> kernel;
            for(int k=0;k<kernelSpace.size();++k){
                int delta =abs(patch[k]-MyMatrixGray(j,i));
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
    QImage croped = Matrixcrop(filtered,size,size);
    return croped;
}
//--------------------------滤波器全部完毕--啦啦啦--6.22 20.10 还有四个小时-------------------

//--------------------------仿射变换，旋转开始------------------------

static void MatrixgetRange(QMatrix& mat,double height,double width,double& MinX,double& MinY,double& MaxX,double& MaxY){
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
static double Matrixbilinear_cal(double v1,double v2,double c1,double c2,double c3){
    if(c1==c2){
        return v1;
    }
    else{
        return (c2-c3)/(c2-c1)*v1+(c3-c1)/(c2-c1)*v2;
    }
}
static double Matrixbilinear(Matrix<int>& img,double originX,double originY){
    //找到四个点
    int x1 = ceil(originX);   //右边
    int x2 = floor(originX);     //左边
    int y1 = ceil(originY);   //下边
    int y2 = floor(originY);     //上边
    //竟然是这里出错 从昨晚八点到今天16点。。。。。。好气啊。ceil对数取大于等于，floor对数值取小于等于。
    //但是在ceil并不总是等于floor+1，比如在边界的时候，这个时候ceil和floor对整数取值结果都是原数值，如果把ceil句写成floor+1，最后矩阵就越界了，
    //但是为什么之前没有转矩阵之前可以用呢？可能是QT有抛出异常之类的。只有边缘几个数值所以结果输出了，异常的部分人眼看不出来。但是自己写的矩阵哪有
    //一有越界直接就报错了。。。。。。晕！仿射变换完成。
    //一开始还以为是其他部分有问题，还想出了把图片的矩阵转置，这样就就可以把矩阵看成是图片了，因为第一个参数就都是宽度，第二个参数就是长度，就不用费力想来想去了。
    //不过这个方法也确实特别棒，之前的颜色处理滤波器什么的应该也可以用。
    /*
    Matrix<int> img = imgg.transpose();
    int rgb1 = img(x1,y1);     //右下角
    int rgb2 = img(x1,y2);     //右上角
    int rgb3 = img(x2,y1);     //左下角
    int rgb4 = img(x2,y2);     //左上角
    */
    int rgb1 = img(y1,x1);
    int rgb2 = img(y2,x1);
    int rgb3 = img(y1,x2);
    int rgb4 = img(y2,x2);

    //red or green or blue (single color per time )
    double temp1,temp2;
    temp1 = Matrixbilinear_cal(rgb2,rgb1,y1,y2,originY);
    temp2 = Matrixbilinear_cal(rgb4,rgb3,y1,y2,originY);
    double singlecolor = Matrixbilinear_cal(temp2,temp1,x1,x2,originX);

    return singlecolor;
}
static double MatrixgetColor(Matrix<int>& img,QMatrix& mat,int i,int j,double MinX,double MinY){
    QMatrix invertmat = mat.inverted();
    double originX,originY;
    invertmat.map(i+MinX,j+MinY,&originX,&originY);
    if(originX<0||originX>img.getNCol()-1||originY<0||originY>img.getNRow()-1){
        return 0;
    }
    else{
        double color = Matrixbilinear(img,originX,originY);

        return color;

        //return 100;
    }

}
static QImage MatrixaffineTransformMatrix(QImage& img,QMatrix& mat){

    Matrix<int> MyMatrixRed = fromQImage(img,'r');
    Matrix<int> MyMatrixGreen = fromQImage(img,'g');
    Matrix<int> MyMatrixBlue = fromQImage(img,'b');

    double imgwidth = (double)MyMatrixRed.getNCol();
    double imgheight = (double)MyMatrixRed.getNRow();

    double MinX,MinY,MaxX,MaxY;
    MatrixgetRange(mat,imgheight,imgwidth,MinX,MinY,MaxX,MaxY);// X=Width  Y=Height
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

    QImage newimg(newwidth,newheight,img.format());
    for(int i = 0;i<newwidth;i++){
        for(int j = 0;j<newheight;j++){
            double r = MatrixgetColor(MyMatrixRed,mat,i,j,MinX,MinY);
            double g = MatrixgetColor(MyMatrixGreen,mat,i,j,MinX,MinY);
            double b = MatrixgetColor(MyMatrixBlue,mat,i,j,MinX,MinY);
            newimg.setPixel(i,j,qRgb(r,g,b));
        }
    }
    return newimg;
}

//--------------------------仿射变换结束------------------------
//--------------------------图像颜色处理、滤波器、仿射变换旋转全部结束。作业要求一、二完成。。。---------

//--------------------------低通高通滤波----------------------------------

static Matrix<int> MatrixHighPassFilter(const Matrix<int>& mat,double threshold){
    int width = mat.getNCol();
    int height = mat.getNRow();
    Matrix<int> ret(height,width,0);
    for(int i = 0; i<height;i++){
        for(int j = 0;j<width;j++){
            double number = sqrt(((i-height/2)*(i-height/2)+(j-width/2)*(j+width/2)));
            if(number>threshold) ret(i,j) = mat(i,j);
            else ret(i,j) = 0;
        }
    }
    return ret;
}

static Matrix<int> MatrixLowPassFilter(const Matrix<int>& mat,double threshold){
    int width = mat.getNCol();
    int height = mat.getNRow();
    Matrix<int> ret(height,width,0);
    for(int i = 0; i<height;i++){
        for(int j = 0;j<width;j++){
            double number = sqrt(((i-height/2)*(i-height/2)+(j-width/2)*(j+width/2)));
            if(number<threshold) ret(i,j) = mat(i,j);
            else ret(i,j) = 0;
        }
    }
    return ret;
}





#endif
