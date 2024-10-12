#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>

template<typename Y>
class Matrix {
private:
    std::vector<std::vector<Y>> instance;


public:

    Matrix(const std::vector<std::vector<Y>>& matrix);

    std::size_t rows_count;
    std::size_t columns_count;

    Matrix<Y> T() const;

    void draw() const;

    Y get_elem(std::size_t row, std::size_t column) const;

    bool set_elem(std::size_t row, std::size_t column, Y value);


    // Перегрузки
    // Перегрузка оператора <<
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);
};

#include "Matrix.tpp"

#endif // MATRIX_H
