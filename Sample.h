//
// Created by Tudoran Eduard on 28.03.2026.
//
#include "Vector.h"
#include "Matrix.h"
#ifndef PROIECT_OOP_SAMPLE_H
#define PROIECT_OOP_SAMPLE_H


class Sample {
    friend Vector;
    friend Matrix;

protected:
    Vector v;
    Matrix m;

public:
    void clear();
    bool check();

    void manuallyInit(Matrix& m_, Vector& v_);


};


#endif //PROIECT_OOP_SAMPLE_H