#ifndef PROIECT_OOP_MATRIX_H
#define PROIECT_OOP_MATRIX_H
#include <iostream>

//matrice patratica? nu neap
class Matrix {
    long long int n;
    long long int m;
    float **v;

public:
    Matrix();
    Matrix(float** v, int n, int m);
    Matrix(Matrix& other);
    ~Matrix();


    void get() const;
    void set(int n_, int m_, float **v_);

    friend std::ostream& operator<<(std::ostream &os, const Matrix &m_);
};


#endif