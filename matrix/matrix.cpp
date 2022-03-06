#include "matrix.h"

Matrix::Matrix(unsigned rows, unsigned cols, double initial = 0){
    _rows = rows;
    _cols = cols;

    v.resize(rows);
    for (unsigned i = 0; i < v.size(); i++)
    {
        v[i].resize(cols, initial);
    }
}

Matrix::Matrix(const Matrix &other)
{
    _cols = other.get_cols();
    _rows = other.get_rows();
    v = other.v;
}

Matrix Matrix::operator+(const Matrix &other){
    Matrix tmp(_cols, _rows, 0.0);

    if(_cols != other.get_cols() || _rows != other.get_rows())
    {
        throw invalid_argument("cols and rows not equal");
    }

    unsigned i, j;
    for (i = 0; i < _rows; i++)
    {
        for (j = 0; j < _cols; j++)
        {
            tmp.v[i][j] = this->v[i][j] + other.v[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator-(const Matrix & other){
    Matrix diff(_cols, _rows, 0.0);

    if(_cols != other.get_cols() || _rows != other.get_rows())
    {
        throw invalid_argument("cols and rows not equal");
    }

    unsigned i,j;
    for (i = 0; i < _rows; i++)
    {
        for (j = 0; j < _cols; j++)
        {
            diff.v[i][j] = this->v[i][j] - other.v[i][j];
        }
    }
    
    return diff;
}

Matrix Matrix::operator*(const Matrix & other){
    Matrix multip(_rows, other.get_cols(), 0.0);
    if(_cols != other.get_rows())
    {
        throw invalid_argument("cols != rows");
    }

    unsigned i,j,k;
    double temp = 0.0;
    for (i = 0; i < _rows; i++)
    {
        for (j = 0; j < other.get_cols(); j++)
        {
            temp = 0.0;
            for (k = 0; k < _cols; k++)
            {
                temp += v[i][k] * other.v[k][j];
            }
            multip.v[i][j] = temp;
        }
    }
    return multip;
}

Matrix Matrix::operator*(double scalar){
    Matrix tmp(_rows,_cols,0.0);
    unsigned i,j;
    for (i = 0; i < _rows; i++)
    {
        for (j = 0; j < _cols; j++)
        {
            tmp.v[i][j] = v[i][j] * scalar;
        }
    }
    return tmp;
}

unsigned Matrix::get_rows() const
{
    return _rows;
}

unsigned Matrix::get_cols() const
{
    return _cols;
}

Matrix Matrix::adamar_product(const Matrix& other)
{
    Matrix temp(_cols, _rows, 0.0);

    if(_cols != other.get_cols() || _rows != other.get_rows())
    {
        throw invalid_argument("cols and rows not equal");
    }

    unsigned int i,j;
    for (i = 0; i < _rows; i++)
    {
        for (j = 0; j < _cols; j++)
        {
            temp.v[i][j] = v[i][j] + other.v[i][j];
        }
    }
    return temp;
}

ostream& operator<<(ostream& os, const Matrix& m)
{
    for (int i = 0; i < m._rows; ++i) {
        os << m.v[i][0];
        for (int j = 1; j < m._cols; ++j) {
            os << " " << m.v[i][j];
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Matrix& m)
{
    for (int i = 0; i < m._rows; ++i) {
        for (int j = 0; j < m._cols; ++j) {
            is >> m.v[i][j];
        }
    }
    return is;
}