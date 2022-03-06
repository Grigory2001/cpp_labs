#include "diagonal_matrix.h"


DiagonalMatrix::DiagonalMatrix(unsigned int dim, vector<double> &init): Matrix{dim, dim, 0} {
    if (_rows != init.size()) {
        throw invalid_argument("rows != init.size()");
    }

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            v[i][j] = i == j ? init[i] : 0;
        }
    }
}