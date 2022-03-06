#include "lower_matrix.h"


LowerMatrix::LowerMatrix(unsigned int dim, vector<vector<double>> &init): Matrix{dim, dim, 0.0} {
    if (_rows != init.size() || _cols != init[0].size()) {
        throw invalid_argument("rows and cols are not equal");
    }

    int k = 0;
    for (int i = 0; i < dim; ++i) {
        k++;
        for (int j = 0; j < k; ++j) {
            if (init[i][j] != 0) {
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