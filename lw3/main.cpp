#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cmath>

#include "matrix.h"


using namespace std;

int main(int argc, char * argv[]) {
    Matrix A(1, 2, 1.0);
    Matrix X(1, 2, 2.0);

    cout << (A.vector_angle(X)) << endl;

    Matrix A1(2, 2, 1.0);

    A1.set_val(0, 1, 2);
    A1.set_val(1, 0, 3);
    A1.set_val(1, 1, 4);

    cout << (A1.inverse()) << endl;
    cout << (A1.det()) << endl;

    return 0;
}
