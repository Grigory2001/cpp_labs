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
    Matrix X(2, 1, 2.0);

    cout << (A.vector_norm()) << endl;

    return 0;
}
