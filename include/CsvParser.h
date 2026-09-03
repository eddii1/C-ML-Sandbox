#ifndef ML_SANDBOX_CSVPARSER_H
#define ML_SANDBOX_CSVPARSER_H

#include <iostream>
#include <string>
#include <vector>

#include "Sample.h"

/**
 * Reads a numeric CSV with a header row into a Sample.
 *
 * The last column is taken as the label and every preceding column as a
 * feature. Parsing is two-pass: the first pass counts valid rows so the Matrix
 * can be allocated once at its final size, the second fills it.
 */
class CsvParser {
    std::string path;
    char delimiter;

    // Splits one CSV line on `delimiter`, trimming surrounding whitespace.
    std::vector<std::string> splitLine(const std::string &line) const;

public:
    explicit CsvParser(const std::string &path, char delimiter = ',');

    const std::string &source() const;

    // Throws std::runtime_error if the file is unreadable or malformed.
    Sample load() const;

    friend std::ostream &operator<<(std::ostream &os, const CsvParser &parser);
};

#endif //ML_SANDBOX_CSVPARSER_H
