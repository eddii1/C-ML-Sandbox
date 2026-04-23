#include "Matrix.h"

// Matrix::Matrix() {
//     this->n = 0;
//     this->m = 0;
//     v = nullptr;
// }

Matrix::Matrix() : size({0,0}), m(nullptr) {}

Matrix::Matrix(pair& size_) {
    if (size_.n <= 0 || size_.m <= 0) {
        this->size = {0, 0};
        this->m = nullptr;
        return;
    }

    this->size = size_;

    this->m = new float*[size_.n];
    for (int i = 0; i < size_.n; i++) {
        this->m[i] = new float[size_.m];
    }
}

Matrix::Matrix(Matrix &other) {
    this->size = other.size;

    this->m = new float*[other.size.n];

    for (int i = 0; i < this->size.n; i++) {
        this->m[i] = new float[this->size.m];

        for (int j = 0; j < this->size.m; j++)
            this->m[i][j] = other.m[i][j];
    }
}

Matrix::~Matrix() {
    clear();
}

void Matrix::get() const {
    if (!check()) {
        std::cout << "MATRICE NEINITIALIZATA\n";
        return;
    }

    std::cout << "Size: " << size.n << "x" << size.m << "\n";
    for (int i = 0; i < size.n; i++) {
        for (int j = 0; j < size.m; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Matrix::set(float **m_, pair& size_) {
    if (check()) {
        clear();
    }

    if (m_ == nullptr || size_.n <= 0 || size_.m <= 0) {
        return;
    }

    this->size = size_;

    this->m = new float*[size_.n];
    for (int i = 0; i < size_.n; i++) {
        this->m[i] = new float[size_.m];
        for (int j = 0; j < size_.m; j++) {
            this->m[i][j] = m_[i][j];
        }
    }
}

void Matrix::clear() {
    int len = this->size.n;

    for (int i = 0; i < len; i++) {
        delete[] this->m[i];
    }
    delete[] this->m;
    this->m = nullptr;
    this->size = {0,0};
}

bool Matrix::check() const {
    return this->size.n > 0 && this->size.m > 0 && this->m != nullptr;
}
