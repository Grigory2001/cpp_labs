#pragma once
#include "matrix.h"


class LowerMatrix: public Matrix {
    public:
        LowerMatrix(unsigned int dim, vector<vector<double>> &init);
};
