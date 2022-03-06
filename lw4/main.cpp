#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cmath>

#include "matrix.h"


using namespace std;

int main(int argc, char * argv[]) {
    Matrix A1(2, 2, 1.0);

    A1.set_val(0, 1, 2);
    A1.set_val(1, 0, 3);
    A1.set_val(1, 1, 4);

    A1.writeBinaryFile("bin_file");
    Matrix B = Matrix::readBinaryFile("bin_file", 2, 2);
    cout << B << endl;

    return 0;
}
