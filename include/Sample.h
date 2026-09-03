#ifndef ML_SANDBOX_SAMPLE_H
#define ML_SANDBOX_SAMPLE_H

#include <iostream>
#include <string>
#include <vector>

#include "Matrix.h"
#include "Vector.h"

/**
 * A loaded dataset: a feature Matrix (one row per observation) composed with a
 * label Vector, plus the column names read from the CSV header.
 *
 * Sample owns no raw memory of its own - Matrix and Vector each manage theirs,
 * so the compiler-generated copy operations are correct here by construction.
 */
class Sample {
    Matrix features;
    Vector labels;
    std::vector<std::string> featureNames;
    std::string labelName;

    // Pearson correlation between two equally sized columns.
    static float correlation(const Vector &a, const Vector &b);

public:
    Sample();
    Sample(const Matrix &features, const Vector &labels,
           const std::vector<std::string> &featureNames, const std::string &labelName);

    bool empty() const;
    void clear();

    int observations() const;
    int featureCount() const;

    const Matrix &featureMatrix() const;
    const Vector &labelVector() const;

    // Per-column mean/stddev/min/max plus label balance, written to `os`.
    void describe(std::ostream &os) const;

    // Ranks features by |correlation| with the label - a crude but honest
    // feature-importance signal, and the first real "model" the sandbox exposes.
    void rankFeaturesByCorrelation(std::ostream &os) const;

    // Returns a copy with every feature column standardised.
    Sample standardized() const;

    friend std::ostream &operator<<(std::ostream &os, const Sample &s);
};

#endif //ML_SANDBOX_SAMPLE_H
