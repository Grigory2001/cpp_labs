#pragma once
#include "matrix.h"


class DiagonalMatrix: public Matrix {
    public:
        DiagonalMatrix(unsigned int dim, vector<double> &init);
};
