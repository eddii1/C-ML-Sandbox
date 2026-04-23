#include "Vector.h"
#include <iostream>

Vector::Vector() {
    std::cout << "--------------- constr_init --------------- \n";
    this->size = 0;
    v = nullptr;
}

Vector::Vector(int &size_) {
    if (size_ <= 0) {
        this->size = 0;
        this->v = nullptr;
        return;
    }

    this->size = size_;
    this->v = new float[this->size];

    for (int i = 0; i < this->size; i++)
        this->v[i] = 0;
}

Vector::Vector(float *v_, int size_) {
    if (size_ <= 0 || v_ == nullptr) {
        this->size = 0;
        this->v = nullptr;
        return;
    }

    this->size = size_;
    this->v = new float[size_];

    for (int i = 0; i < size_; i ++)
        this->v[i] = v_[i];
}

Vector::Vector(Vector &other) {
    if (!other.check()) {
        this->size = 0;
        this->v = nullptr;
        return;
    }

    this->size = other.size;
    this->v = new float[this->size];

    for (int i = 0; i < this->size; i++)
        this->v[i] = other.v[i];
}

void Vector::get() const {
    if (!check()) {
        std::cout << "VECTOR NEINITIALIZAT\n\n";
        return;
    }

    std::cout << "Size is: " << this->size << '\n';

    std::cout << "Vector is: (";
    for (int i = 0; i < size - 1; i++)

        std::cout << this->v[i] << " , ";
    std::cout << v[size-1] << ")" << '\n';
    std::cout << '\n';
}

void Vector::set(int size_, float *v_){
    clear();

    if (size_ <= 0 || v_ == nullptr) {
        return;
    }

    this->size = size_;
    this->v = new float[this->size];

    for (int i = 0; i < size_; i++)
        this->v[i] = v_[i];
}

void Vector::clear() {
    delete[] v;
    this->v = nullptr;
    this->size = 0;
}

void Vector::setInterval(float *v_, int start= 0, int final= 9){
    if (final > this->size)
        return;
    else
        for (int i = start; i < final; i++)
            this->v[i] = v_[i];
}

bool Vector::check() const {
    return this->size > 0 && this->v != nullptr;
}

std::ostream& operator<<(std::ostream &os, const Vector &v_) {
    os << "Vector is : (";
    for (int i = 0; i < v_.size; i++)
        os << v_.v[i] << ",";

    os << ")";
    os << '\n';
    return os;
}
Vector::~Vector() {
    std::cout << "--------------- deconstr --------------- \n";
    std::cout << "Size before destructing: " << size << '\n';
    clear();
}
