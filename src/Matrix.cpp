#include "Matrix.h"

#include <stdexcept>

void Matrix::release() {
    for (int i = 0; i < shape.rows; i++)
        delete[] cells[i];
    delete[] cells;

    cells = nullptr;
    shape = {0, 0};
}

void Matrix::allocate(Shape s) {
    if (s.rows < 0 || s.cols < 0)
        throw std::invalid_argument("Matrix: negative dimension");

    if (s.rows == 0 || s.cols == 0) {
        cells = nullptr;
        shape = {0, 0};
        return;
    }

    cells = new float *[s.rows];
    for (int i = 0; i < s.rows; i++)
        cells[i] = new float[s.cols]();
    shape = s;
}

Matrix::Matrix() : shape({0, 0}), cells(nullptr) {}

Matrix::Matrix(Shape size) : shape({0, 0}), cells(nullptr) {
    allocate(size);
}

Matrix::Matrix(const Matrix &other) : shape({0, 0}), cells(nullptr) {
    allocate(other.shape);
    for (int i = 0; i < shape.rows; i++)
        for (int j = 0; j < shape.cols; j++)
            cells[i][j] = other.cells[i][j];
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this == &other)
        return *this;

    release();
    allocate(other.shape);
    for (int i = 0; i < shape.rows; i++)
        for (int j = 0; j < shape.cols; j++)
            cells[i][j] = other.cells[i][j];
    return *this;
}

Matrix::~Matrix() {
    release();
}

Matrix::Shape Matrix::size() const {
    return shape;
}

int Matrix::rows() const {
    return shape.rows;
}

int Matrix::cols() const {
    return shape.cols;
}

bool Matrix::empty() const {
    return shape.rows == 0 || shape.cols == 0;
}

void Matrix::clear() {
    release();
}

float *Matrix::operator[](int row) {
    if (row < 0 || row >= shape.rows)
        throw std::out_of_range("Matrix: row out of range");
    return cells[row];
}

const float *Matrix::operator[](int row) const {
    if (row < 0 || row >= shape.rows)
        throw std::out_of_range("Matrix: row out of range");
    return cells[row];
}

void Matrix::setRow(int row, const Vector &values) {
    if (row < 0 || row >= shape.rows)
        throw std::out_of_range("Matrix: row out of range");
    if (values.size() != shape.cols)
        throw std::invalid_argument("Matrix: row width mismatch");

    for (int j = 0; j < shape.cols; j++)
        cells[row][j] = values[j];
}

Vector Matrix::column(int index) const {
    if (index < 0 || index >= shape.cols)
        throw std::out_of_range("Matrix: column out of range");

    Vector out(shape.rows);
    for (int i = 0; i < shape.rows; i++)
        out[i] = cells[i][index];
    return out;
}

Matrix Matrix::standardized() const {
    Matrix out(*this);
    for (int j = 0; j < shape.cols; j++) {
        const Vector scaled = column(j).standardized();
        for (int i = 0; i < shape.rows; i++)
            out.cells[i][j] = scaled[i];
    }
    return out;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    os << m.shape.rows << "x" << m.shape.cols << "\n";
    for (int i = 0; i < m.shape.rows; i++) {
        for (int j = 0; j < m.shape.cols; j++)
            os << m.cells[i][j] << (j + 1 < m.shape.cols ? "\t" : "");
        os << "\n";
    }
    return os;
}
