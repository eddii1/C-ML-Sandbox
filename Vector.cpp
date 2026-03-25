#include "Vector.h"
#include <iostream>

Vector::Vector() {
    std::cout << "--------------- constr_init --------------- \n";
    this->size = 0;
    v = nullptr;
}

Vector::Vector(int &size_) {
    this->size = size_;
}

Vector::Vector(int *v_, int size_) {
    this->size = size_;
    this->v = new float[size_];

    for (int i = 0; i < size_; i ++)
        this->v[i] = v_[i];
}

Vector::Vector(Vector &other) {
    this->size = other.size;
    if (other.v != nullptr)
        for (int i = 0; i < this->size; i++)
            this->v[i] = other.v[i];
    else
        this->v = nullptr;
}

Vector::~Vector() {
    std::cout << "Size before destructing: " << size << '\n';
    std::cout << "--------------- deconstr --------------- \n";
    this->size = 0;
    delete[] v;
}

void Vector::get() const {
    std::cout << "Size is: " << this->size << '\n';

    std::cout << "Vector is: (";
    for (int i = 0; i < size - 1; i++)
        std::cout << this->v[i] << " , ";
    std::cout << v[size-1] << ")" << '\n';
}

void Vector::set(int &size_, float *v_){
    this->size = size_;
    for (int i = 0; i < size_; i++)
        this->v[i] = v_[i];
}

void Vector::setInterval(float *v_, int start= 0, int final= 9){
    if (final > this->size)
        return;
    else
        for (int i = start; i < final; i++)
            this->v[i] = v_[i];
}

std::ostream& operator<<(std::ostream &os, const Vector &v_) {
    os << "Vector is : (";
    for (int i = 0; i < 9; i++)
        //os << v_[i] << ",";
    //os << ")";
    return os;
}

