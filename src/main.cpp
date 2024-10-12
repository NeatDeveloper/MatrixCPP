#include <iostream>
#include "Matrix.h"

int main() {
    Matrix<int> matrix(3, 3);

    std::cin >> matrix;

    std::cout << matrix.is_cute();

    return 0;
}
