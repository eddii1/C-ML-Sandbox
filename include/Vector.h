#ifndef ML_SANDBOX_VECTOR_H
#define ML_SANDBOX_VECTOR_H

#include <iostream>

/**
 * Dense vector of floats over raw, owned heap storage.
 *
 * Written against `new[]`/`delete[]` on purpose: the point of the project is to
 * carry the ownership rules by hand rather than delegate them to std::vector.
 * Follows the rule of three (copy constructor, copy assignment, destructor).
 */
class Vector {
    float *data;
    int len;

    // Releases the current buffer and leaves the object in the empty state.
    void release();

public:
    Vector();
    explicit Vector(int size);
    Vector(const float *values, int size);
    Vector(const Vector &other);
    Vector &operator=(const Vector &other);
    ~Vector();

    int size() const;
    bool empty() const;
    void clear();

    float &operator[](int i);
    const float &operator[](int i) const;

    void assign(const float *values, int size);
    void assignRange(const float *values, int first, int last);

    // Descriptive statistics, used by the normalisation step.
    float mean() const;
    float stddev() const;
    float dot(const Vector &other) const;

    // Returns a zero-mean, unit-variance copy. A constant vector is returned as zeros.
    Vector standardized() const;

    friend std::ostream &operator<<(std::ostream &os, const Vector &v);
};

#endif //ML_SANDBOX_VECTOR_H
