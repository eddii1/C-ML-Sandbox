#include "Sample.h"

#include <algorithm>
#include <cmath>
#include <iomanip>

Sample::Sample() = default;

Sample::Sample(const Matrix &features_, const Vector &labels_,
               const std::vector<std::string> &featureNames_, const std::string &labelName_)
    : features(features_), labels(labels_), featureNames(featureNames_), labelName(labelName_) {}

bool Sample::empty() const {
    return features.empty() || labels.empty();
}

void Sample::clear() {
    features.clear();
    labels.clear();
    featureNames.clear();
    labelName.clear();
}

int Sample::observations() const {
    return features.rows();
}

int Sample::featureCount() const {
    return features.cols();
}

const Matrix &Sample::featureMatrix() const {
    return features;
}

const Vector &Sample::labelVector() const {
    return labels;
}

float Sample::correlation(const Vector &a, const Vector &b) {
    const float sa = a.stddev();
    const float sb = b.stddev();
    if (sa == 0.0f || sb == 0.0f)
        return 0.0f;

    // With both columns standardised, the correlation is just the scaled dot product.
    return a.standardized().dot(b.standardized()) / static_cast<float>(a.size());
}

void Sample::describe(std::ostream &os) const {
    if (empty()) {
        os << "No sample loaded.\n";
        return;
    }

    os << observations() << " observations, " << featureCount() << " features\n\n";
    os << std::left << std::setw(20) << "feature"
       << std::right << std::setw(12) << "mean"
       << std::setw(12) << "stddev"
       << std::setw(12) << "min"
       << std::setw(12) << "max" << "\n";

    for (int j = 0; j < featureCount(); j++) {
        const Vector col = features.column(j);
        float lo = col[0], hi = col[0];
        for (int i = 1; i < col.size(); i++) {
            lo = std::min(lo, col[i]);
            hi = std::max(hi, col[i]);
        }

        os << std::left << std::setw(20) << featureNames[j]
           << std::right << std::fixed << std::setprecision(3)
           << std::setw(12) << col.mean()
           << std::setw(12) << col.stddev()
           << std::setw(12) << lo
           << std::setw(12) << hi << "\n";
    }

    os << "\nlabel '" << labelName << "': mean " << labels.mean()
       << ", stddev " << labels.stddev() << "\n";
    os << std::defaultfloat;
}

void Sample::rankFeaturesByCorrelation(std::ostream &os) const {
    if (empty()) {
        os << "No sample loaded.\n";
        return;
    }

    std::vector<std::pair<float, int> > ranked;
    ranked.reserve(featureCount());
    for (int j = 0; j < featureCount(); j++)
        ranked.emplace_back(correlation(features.column(j), labels), j);

    std::sort(ranked.begin(), ranked.end(),
              [](const std::pair<float, int> &a, const std::pair<float, int> &b) {
                  return std::fabs(a.first) > std::fabs(b.first);
              });

    os << "Features ranked by |correlation| with '" << labelName << "':\n\n";
    os << std::left << std::setw(6) << "rank" << std::setw(20) << "feature"
       << std::right << std::setw(12) << "corr" << "\n";

    for (std::size_t k = 0; k < ranked.size(); k++)
        os << std::left << std::setw(6) << (k + 1)
           << std::setw(20) << featureNames[ranked[k].second]
           << std::right << std::fixed << std::setprecision(3)
           << std::setw(12) << ranked[k].first << "\n";
    os << std::defaultfloat;
}

Sample Sample::standardized() const {
    return Sample(features.standardized(), labels, featureNames, labelName);
}

std::ostream &operator<<(std::ostream &os, const Sample &s) {
    if (s.empty()) {
        os << "Sample: empty\n";
        return os;
    }

    os << "Sample: " << s.observations() << " x " << s.featureCount() << "\n";
    os << "features:\n" << s.features;
    os << "labels (" << s.labelName << "): " << s.labels << "\n";
    return os;
}
