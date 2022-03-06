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

void Matrix::set_val(int i, int j, double val)
{
    v[i][j] = val;
}

double Matrix::dot_product(const Matrix &other_vec) {
    double res = 0;

    for (int i = 0; i < _rows; i++) {
        double a, b;
        res += v[0][i] * other_vec.v[0][i];
    }

    return res;
}

double Matrix::vector_norm() {
  return sqrt(inner_product(v[0].begin(), v[0].end(), v[0].begin(), 0.0));
}

double Matrix::frobenius_norm()
{
    Matrix temp(*this);

    unsigned int i,j;
    for (i = 0; i < _rows; i++)
    {
        for (j = 0; j < _cols; j++)
        {
            temp.v[i][j] *= temp.v[i][j];
        }
    }

    double sum = 0;
    for (i = 0; i < _rows; i++)
    {
        for (j = 0; j < _cols; j++)
        {
            sum += temp.v[i][j];
        }
    }

    return sum;
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


double Matrix::det()
{
    int N = v.size();
    double det = 1;

    for (int i = 0; i < N; ++i) {

        double pivotElement = v[i][i];
        int pivotRow = i;
        for (int row = i + 1; row < N; ++row) {
            if (std::abs(v[row][i]) > std::abs(pivotElement)) {
                pivotElement = v[row][i];
                pivotRow = row;
            }
        }
        if (pivotElement == 0.0) {
            return 0.0;
        }
        if (pivotRow != i) {
            v[i].swap(v[pivotRow]);
            det *= -1.0;
        }
        det *= pivotElement;

        for (int row = i + 1; row < N; ++row) {
            for (int col = i + 1; col < N; ++col) {
                v[row][col] -= v[row][i] * v[i][col] / pivotElement;
            }
        }
    }

    return det;
}

double Matrix::trace()
{
    double tmp = 0;

    if (_cols != _rows) 
    {
        throw invalid_argument("not square matrix");
    }

    for (unsigned i = 0; i < _cols; i++)
    {
        tmp += v[i][i];
    }

    return tmp;
}

Matrix Matrix::transpose()
{
    Matrix tmp(_cols, _rows, 0.0);
    for (unsigned i = 0; i < _cols; i++)
    {
        for (unsigned j = 0; j < _rows; j++) {
            tmp.v[i][j] = v[j][i];
        }
    }
    return tmp;
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