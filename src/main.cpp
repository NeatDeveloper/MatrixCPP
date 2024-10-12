#include <iostream>
#include "Matrix.h"

int main() {
    int size;

    std::cin >> size;

    Matrix<int> matrix(size, 0);

    std::cin >> matrix;

    std::cout << matrix;
    std::cout << matrix.sum_above_main_diagonal();

    return 0;
}
