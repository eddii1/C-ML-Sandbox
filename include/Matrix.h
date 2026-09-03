#ifndef ML_SANDBOX_MATRIX_H
#define ML_SANDBOX_MATRIX_H

#include <iostream>

#include "Vector.h"

/**
 * Row-major matrix of floats over an owned array of row pointers.
 *
 * Rows are the samples of a dataset and columns are its features, which is why
 * the non-trivial operations here (column extraction, standardisation) work
 * column-wise.
 */
class Matrix {
public:
    struct Shape {
        int rows;
        int cols;
    };

private:
    Shape shape;
    float **cells;

    void release();
    void allocate(Shape s);

public:
    Matrix();
    explicit Matrix(Shape size);
    Matrix(const Matrix &other);
    Matrix &operator=(const Matrix &other);
    ~Matrix();

    Shape size() const;
    int rows() const;
    int cols() const;
    bool empty() const;
    void clear();

    float *operator[](int row);
    const float *operator[](int row) const;

    void setRow(int row, const Vector &values);

    // Copies out one feature column as a Vector.
    Vector column(int index) const;

    // Standardises every column independently (zero mean, unit variance).
    Matrix standardized() const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
};

#endif //ML_SANDBOX_MATRIX_H
