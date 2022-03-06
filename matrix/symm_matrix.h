#pragma once
#include "matrix.h"


class SymmMatrix: public Matrix {
    public:
        SymmMatrix(unsigned int dim, vector<vector<double>> &init);
};
