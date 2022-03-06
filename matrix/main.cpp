#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cmath>

#include "matrix.h"


using namespace std;

int main(int argc, char * argv[]) {
    Matrix A(2, 2, 1.0);
    Matrix X(2, 1, 2.0);

    cout << (A * X) << endl;

    return 0;
}
