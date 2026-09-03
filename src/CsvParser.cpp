#include "CsvParser.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

CsvParser::CsvParser(const std::string &path_, char delimiter_)
    : path(path_), delimiter(delimiter_) {}

const std::string &CsvParser::source() const {
    return path;
}

std::vector<std::string> CsvParser::splitLine(const std::string &line) const {
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;

    while (std::getline(ss, field, delimiter)) {
        const std::size_t first = field.find_first_not_of(" \t\r\n");
        const std::size_t last = field.find_last_not_of(" \t\r\n");
        fields.push_back(first == std::string::npos ? "" : field.substr(first, last - first + 1));
    }
    return fields;
}

Sample CsvParser::load() const {
    std::ifstream file(path);
    if (!file.is_open())
        throw std::runtime_error("CsvParser: cannot open '" + path + "'");

    std::string line;
    if (!std::getline(file, line))
        throw std::runtime_error("CsvParser: '" + path + "' is empty");

    const std::vector<std::string> header = splitLine(line);
    if (header.size() < 2)
        throw std::runtime_error("CsvParser: need at least one feature column and one label column");

    const int columns = static_cast<int>(header.size());
    const int featureCount = columns - 1;

    // First pass: count the rows that are well formed, so the Matrix is sized once.
    std::vector<std::vector<float> > parsed;
    int lineNumber = 1;
    while (std::getline(file, line)) {
        lineNumber++;
        if (line.find_first_not_of(" \t\r\n") == std::string::npos)
            continue;

        const std::vector<std::string> fields = splitLine(line);
        if (static_cast<int>(fields.size()) != columns)
            throw std::runtime_error("CsvParser: line " + std::to_string(lineNumber) +
                                     " has " + std::to_string(fields.size()) +
                                     " fields, expected " + std::to_string(columns));

        std::vector<float> row;
        row.reserve(columns);
        for (int j = 0; j < columns; j++) {
            try {
                row.push_back(std::stof(fields[j]));
            } catch (const std::exception &) {
                throw std::runtime_error("CsvParser: line " + std::to_string(lineNumber) +
                                         ", column '" + header[j] + "': '" + fields[j] +
                                         "' is not numeric");
            }
        }
        parsed.push_back(row);
    }

    if (parsed.empty())
        throw std::runtime_error("CsvParser: '" + path + "' has a header but no data rows");

    // Second pass: fill the owned containers.
    const int rows = static_cast<int>(parsed.size());
    Matrix features(Matrix::Shape{rows, featureCount});
    Vector labels(rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < featureCount; j++)
            features[i][j] = parsed[i][j];
        labels[i] = parsed[i][featureCount];
    }

    const std::vector<std::string> featureNames(header.begin(), header.end() - 1);
    return Sample(features, labels, featureNames, header.back());
}

std::ostream &operator<<(std::ostream &os, const CsvParser &parser) {
    os << "CsvParser('" << parser.path << "', delimiter '" << parser.delimiter << "')";
    return os;
}
