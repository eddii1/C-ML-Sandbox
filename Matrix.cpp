#include "Matrix.h"

// Matrix::Matrix() {
//     this->n = 0;
//     this->m = 0;
//     v = nullptr;
// }

Matrix::Matrix() : n(0), m(0), v(nullptr) {}

Matrix::Matrix(float **v_, int n_, int m_) {
    this->n = n_;
    this->m = m_;

    this->v = new float*[n_];
    for (int i = 0; i < n_; i++) {
        this->v[i] = new float[m_];
    }
}

Matrix::Matrix(Matrix &other) {
    this->n = other.n;
    this->m = other.m;

    this->v = new float*[this->n];

    for (int i = 0; i < this->n; i++) {
        this->v[i] = new float[this->m];

        for (int j = 0; j < this->m; j++)
            this->v[i][j] = other.v[i][j];
    }
}

Matrix::~Matrix() {
    int len = this->n;
    this->n = 0;
    this->m = 0;

    for (int i = 0; i < len; i++) {
        delete[] this->v[i];
    }
    delete[] this->v;
}

void Matrix::get() const {
    std::cout << "Size: " << n << "x" << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void Matrix::set(int n_, int m_, float **v_) {
    this->n = n_;
    this->m = m_;

    this->v = new float*[n];
    for (int i = 0; i < n; i++) {
        this->v[i] = new float[m];
        for (int j = 0; j < m; j++) {
            this->v[i][j] = v_[i][j];
        }
    }
}

