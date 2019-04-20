#ifndef __MATRIX_H
#define __MATRIX_H

#include <iostream>
#include <math.h>

#include "basecontainer.h"
#include "iterator.hpp"
#include "linematrix.hpp"

template <typename T>
class Matrix : public BaseContainer
{
public:
    Matrix();
    Matrix(size_t n);
    Matrix(size_t n, size_t m, T** mat = nullptr);
    Matrix(std::initializer_list< std::initializer_list<T> > list);
    ~Matrix() override;

    explicit Matrix(const Matrix<T>& copied);
    Matrix(Matrix<T>&& copied);
    Matrix<T>& operator=(const Matrix<T>& copied);
    Matrix<T>& operator=(Matrix<T>&& copied);

    int rows() const override;
    int columns() const override;

    operator bool() const override;

    const T& get(size_t i, size_t j) const;
    T& get(size_t  i, size_t  j);
    const T& operator()(size_t  i, size_t  j) const;
    T& operator()(size_t  i, size_t  j);

    LineMatrix<T> operator[](size_t  i);
    const LineMatrix<T> operator[](size_t  i) const;

    Matrix<T>& addColumn();
    Matrix<T>& addRow();

    Matrix<T> addition(const Matrix<T>& mat);
    Matrix<T>& additionSelf(const Matrix<T>& mat);
    Matrix<T> operator+(const Matrix<T>& mat);
    Matrix<T>& operator+=(const Matrix<T>& mat);
    Matrix<T> addition(const Matrix<T>& mat) const;
    Matrix<T> operator+(const Matrix<T>& mat) const;

    Matrix<T> subtraction(const Matrix<T>& mat);
    Matrix<T>& subtractionSelf(const Matrix<T>& mat);
    Matrix<T> operator-(const Matrix<T>& mat);
    Matrix<T>& operator-=(const Matrix<T>& mat);
    Matrix<T> subtraction(const Matrix<T>& mat) const;
    Matrix<T> operator-(const Matrix<T>& mat) const;

    Matrix<T> multiplication(const Matrix<T>& mat);
    Matrix<T>& multiplicationSelf(const Matrix<T>& mat);
    Matrix<T> operator*(const Matrix<T>& mat);
    Matrix<T>& operator*=(const Matrix<T>& mat);
    Matrix<T> multiplication(const Matrix<T>& mat) const;
    Matrix<T> operator*(const Matrix<T>& mat) const;

    Matrix<T> addition(const T& element);
    Matrix<T>& additionSelf(const T& element);
    Matrix<T> operator+(const T& element);
    Matrix<T>& operator+=(const T& element);
    Matrix<T> addition(const T& element) const;
    Matrix<T> operator+(const T& element) const;

    Matrix<T> subtraction(const T& element);
    Matrix<T>& subtractionSelf(const T& element);
    Matrix<T> operator-(const T& element);
    Matrix<T>& operator-=(const T& element);
    Matrix<T> subtraction(const T& element) const;
    Matrix<T> operator-(const T& element) const;

    Matrix<T> multiplication(const T& element);
    Matrix<T>& multiplicationSelf(const T& element);
    Matrix<T> operator*(const T& element);
    Matrix<T>& operator*=(const T& element);
    Matrix<T> multiplication(const T& element) const;
    Matrix<T> operator*(const T& element) const;

    Matrix<T> division(const T& element);
    Matrix<T>& divisionSelf(const T& element);
    Matrix<T> operator/(const T& element);
    Matrix<T>& operator/=(const T& element);
    Matrix<T> division(const T& element) const;
    Matrix<T> operator/(const T& element) const;

    Matrix<T> inverse();
    Matrix<T> operator-();
    Matrix<T>& inverseSelf();

    Matrix<T> transposition();
    Matrix<T>& transpositionSelf();

    T determinant();

    MatrixIterator<T> begin();
    MatrixIterator<T> end();
    ConstMatrixIterator<const T> begin() const;
    ConstMatrixIterator<const T> end() const;

private:
    std::shared_ptr<T> data;
    Matrix<T> getMatrixWithoutRowAndCol(size_t row, size_t col);
};

#endif // __MATRIX_H

