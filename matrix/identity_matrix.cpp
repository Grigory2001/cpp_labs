#include "identity_matrix.h"


IdentityMatrix::IdentityMatrix(unsigned int dim): Matrix{dim, dim, 0} {
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            v[i][j] = i == j ? 1 : 0;
        }
    }
}