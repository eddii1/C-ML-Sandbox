#include "Vector.h"

#include <cmath>
#include <stdexcept>

void Vector::release() {
    delete[] data;
    data = nullptr;
    len = 0;
}

Vector::Vector() : data(nullptr), len(0) {}

Vector::Vector(int size) : data(nullptr), len(0) {
    if (size < 0)
        throw std::invalid_argument("Vector: negative size");
    if (size > 0) {
        data = new float[size]();
        len = size;
    }
}

Vector::Vector(const float *values, int size) : data(nullptr), len(0) {
    assign(values, size);
}

Vector::Vector(const Vector &other) : data(nullptr), len(0) {
    assign(other.data, other.len);
}

Vector &Vector::operator=(const Vector &other) {
    if (this != &other)
        assign(other.data, other.len);
    return *this;
}

Vector::~Vector() {
    release();
}

int Vector::size() const {
    return len;
}

bool Vector::empty() const {
    return len == 0;
}

void Vector::clear() {
    release();
}

float &Vector::operator[](int i) {
    if (i < 0 || i >= len)
        throw std::out_of_range("Vector: index out of range");
    return data[i];
}

const float &Vector::operator[](int i) const {
    if (i < 0 || i >= len)
        throw std::out_of_range("Vector: index out of range");
    return data[i];
}

void Vector::assign(const float *values, int size) {
    if (size < 0)
        throw std::invalid_argument("Vector: negative size");

    // Allocate first, so a throwing allocation leaves the old buffer intact.
    float *fresh = (size > 0) ? new float[size] : nullptr;
    for (int i = 0; i < size; i++)
        fresh[i] = (values != nullptr) ? values[i] : 0.0f;

    release();
    data = fresh;
    len = size;
}

void Vector::assignRange(const float *values, int first, int last) {
    if (values == nullptr)
        throw std::invalid_argument("Vector: null source");
    if (first < 0 || last > len || first > last)
        throw std::out_of_range("Vector: invalid range");

    for (int i = first; i < last; i++)
        data[i] = values[i - first];
}

float Vector::mean() const {
    if (empty())
        return 0.0f;

    float sum = 0.0f;
    for (int i = 0; i < len; i++)
        sum += data[i];
    return sum / static_cast<float>(len);
}

float Vector::stddev() const {
    if (len < 2)
        return 0.0f;

    const float mu = mean();
    float acc = 0.0f;
    for (int i = 0; i < len; i++)
        acc += (data[i] - mu) * (data[i] - mu);
    return std::sqrt(acc / static_cast<float>(len));
}

float Vector::dot(const Vector &other) const {
    if (len != other.len)
        throw std::invalid_argument("Vector: dot product of mismatched sizes");

    float acc = 0.0f;
    for (int i = 0; i < len; i++)
        acc += data[i] * other.data[i];
    return acc;
}

Vector Vector::standardized() const {
    Vector out(*this);
    const float sigma = stddev();
    const float mu = mean();

    // A constant column carries no signal; collapse it to zeros instead of dividing by 0.
    if (sigma == 0.0f) {
        for (int i = 0; i < out.len; i++)
            out.data[i] = 0.0f;
        return out;
    }

    for (int i = 0; i < out.len; i++)
        out.data[i] = (out.data[i] - mu) / sigma;
    return out;
}

std::ostream &operator<<(std::ostream &os, const Vector &v) {
    os << "(";
    for (int i = 0; i < v.len; i++) {
        os << v.data[i];
        if (i + 1 < v.len)
            os << ", ";
    }
    os << ")";
    return os;
}
