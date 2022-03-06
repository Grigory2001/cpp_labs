#include <vector>
#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;

class Matrix {
protected:
    unsigned _rows;
    unsigned _cols;
    vector<vector<double>> v;
public:
    Matrix(unsigned, unsigned, double);
    Matrix(const Matrix&);
    
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix transpose();
    
    Matrix operator*(double);
    Matrix adamar_product(const Matrix& other);

    friend ostream& operator<<(ostream& os, const Matrix& m);
    friend istream& operator>>(istream&, Matrix&);

    unsigned get_rows() const;
    unsigned get_cols() const;
};
