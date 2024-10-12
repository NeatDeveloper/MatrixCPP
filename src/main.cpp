#include <iostream>
#include "Matrix.h"

int main() {
    Matrix<int> matrix({
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    });

    std::cout << matrix;
    std::cout << matrix.T();

    return 0;
}
