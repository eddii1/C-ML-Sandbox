#ifndef PROIECT_OOP_VECTOR_H
#define PROIECT_OOP_VECTOR_H
#include <iostream>

class Vector {
//size
    float* v;
protected:
    long long int size;

public:
    Vector();
    Vector(int& size);
    Vector(int* v, int size);
    Vector(Vector &other);
    ~Vector();

    void get () const;
    void set(int& size_, float *v_);
    void setInterval(float *v_, int start, int final);

    friend std::ostream operator<<(std::ostream &os, const Vector v_);

    //getter & setter function.
};


#endif //PROIECT_OOP_VECTOR_H