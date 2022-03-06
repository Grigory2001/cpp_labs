#include "upper_matrix.h"


UpperMatrix::UpperMatrix(unsigned int dim, vector<vector<double>> &init): Matrix{dim, dim, 0.0} {
    if (_rows != init.size() && _cols != init[0].size()) {
        throw invalid_argument("rows and cols are not equal");
    }

    int k = dim;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < k; ++j) {
            if (init[i][j] != 0) {
                throw invalid_argument("not upper matrix");
            }
        }
        k--;
    }

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            v[i][j] = init[i][j];
        }
    }
}