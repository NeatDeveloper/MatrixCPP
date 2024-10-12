#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>

template<typename Y>
class Matrix {
public:
    std::vector<std::vector<Y>> instance;

    Matrix(const std::vector<std::vector<Y>>& matrix);
    Matrix(size_t rows, size_t columns);

    std::size_t rows_count;
    std::size_t columns_count;

    Matrix<Y> T() const;

    Y get_elem(std::size_t row, std::size_t column) const;

    bool set_elem(std::size_t row, std::size_t column, Y value);

    Y sum_above_main_diagonal() const;
    Y sum_above_side_diagonal() const;

    Y sum_below_main_diagonal() const;
    Y sum_below_side_diagonal() const;

    bool is_cute();

    // Перегрузки
    // Перегрузка оператора <<
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);
};

#include "Matrix.tpp"

#endif // MATRIX_H
