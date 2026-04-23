#ifndef PROIECT_OOP_MATRIX_H
#define PROIECT_OOP_MATRIX_H
#include <iostream>

//matrice patratica? nu neap
class Matrix {
    struct pair {
        int n, m;
    };
    pair size;
    float **m;

public:
    Matrix();
    Matrix(pair& size);
    Matrix(Matrix& other);
    ~Matrix();


    bool check();
    void clear();
    void get() const;
    void set(float **m, pair&size);

    friend std::ostream& operator<<(std::ostream &os, const Matrix &m_);
};


#endif