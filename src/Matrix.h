#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

template<typename Y>
class Matrix {
public:
    std::vector<std::vector<Y>> instance;

    Matrix(const std::vector<std::vector<Y>>& matrix);
    Matrix(size_t rows, size_t columns, size_t default_value);
    Matrix(size_t size, size_t default_value);

    Y max();

    std::size_t rows_count;
    std::size_t columns_count;

    Matrix<Y> T() const;

    Y get_elem(std::size_t row, std::size_t column) const;

    bool set_elem(std::size_t row, std::size_t column, Y value);

    Y sum_above_main_diagonal();
    Y sum_above_side_diagonal();

    Y sum_below_main_diagonal();
    Y sum_below_side_diagonal();

    bool is_cute();

    // Перегрузки

    // Перегрузка оператора <<
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<Y>& matrix);

    // Перегрузка оператора <<
    template<typename U>
    friend std::istream& operator>>(std::istream& is, Matrix<Y>& matrix);


    // Перегрузка операторов + - * / %
    Matrix<Y> operator+(const Matrix<Y>& other) const;
    Matrix<Y> operator-(const Matrix<Y>& other) const;
    Matrix<Y> operator*(const Matrix<Y>& other) const;
    Matrix<Y> operator/(const Matrix<Y>& other) const;
    Matrix<Y> operator%(const Matrix<Y>& other) const;
};

#include "Matrix.tpp"

#endif // MATRIX_H
