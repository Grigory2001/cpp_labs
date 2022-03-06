#include <vector>
#include <iostream>
#include <tuple>
#include <cmath>
#include <numeric>

using namespace std;

class Matrix {
protected:
    unsigned _rows;
    unsigned _cols;
    vector<vector<double>> v;
public:
    Matrix(unsigned, unsigned, double);
    Matrix(const Matrix&);
    void set_val(int i, int j, double val);

    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix transpose();
    double dot_product(const Matrix &other_vec);
    double vector_norm();
    double frobenius_norm();
    double trace();
    double det();
    int compute_rank();
    double vector_angle(Matrix v1);
    Matrix get_minor(int row, int col);
    Matrix cofactor();
    Matrix inverse();
    Matrix operator*(double);
    Matrix adamar_product(const Matrix& other);

    friend ostream& operator<<(ostream& os, const Matrix& m);
    friend istream& operator>>(istream&, Matrix&);

    unsigned get_rows() const;
    unsigned get_cols() const;
};
