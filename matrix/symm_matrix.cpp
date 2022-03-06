#include "symm_matrix.h"


SymmMatrix::SymmMatrix(unsigned int dim, vector<vector<double>> &init): Matrix{dim, dim, 0.0} {
    if (_rows != init.size() || _cols != init[0].size()) {
        throw invalid_argument("rows and cols are not equal");
    }

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            if (init[i][j] != init[j][i]) {
                throw invalid_argument("not symm matrix");
            }
        }
    }

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            v[i][j] = init[i][j];
        }
    }
}