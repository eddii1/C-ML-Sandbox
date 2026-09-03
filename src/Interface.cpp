#include "Interface.h"

#include <iostream>
#include <limits>

#include "CsvParser.h"

Interface::Interface() : running(false) {}

Interface::Interface(const std::string &path) : running(false) {
    loadFrom(path);
}

void Interface::printMenu() const {
    std::cout << "\n----------------------------------------\n";
    std::cout << " C++ ML Sandbox";
    if (!sample.empty())
        std::cout << "  [" << sample.observations() << " x " << sample.featureCount() << " loaded]";
    std::cout << "\n----------------------------------------\n";
    std::cout << " 1. Load a CSV dataset\n";
    std::cout << " 2. Enter a sample by hand\n";
    std::cout << " 3. Summary statistics\n";
    std::cout << " 4. Rank features by correlation\n";
    std::cout << " 5. Standardize features in place\n";
    std::cout << " 6. Print the raw sample\n";
    std::cout << " 7. Clear the sample\n";
    std::cout << " 0. Quit\n";
    std::cout << "> ";
}

bool Interface::readChoice(int &choice) const {
    if (std::cin >> choice)
        return true;

    if (std::cin.eof())
        return false;

    // Non-numeric input: drop the bad token and let the caller re-prompt.
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    choice = -1;
    return true;
}

void Interface::loadSample() {
    if (!sample.empty())
        std::cout << "A sample is already loaded; it will be replaced.\n";

    std::cout << "CSV path: ";
    std::string path;
    if (!(std::cin >> path))
        return;

    loadFrom(path);
}

void Interface::enterSampleManually() {
    if (!sample.empty())
        std::cout << "A sample is already loaded; it will be replaced.\n";

    int rows = 0, cols = 0;
    std::cout << "Observations (rows): ";
    if (!(std::cin >> rows))
        return;
    std::cout << "Features per observation (columns): ";
    if (!(std::cin >> cols))
        return;

    if (rows <= 0 || cols <= 0) {
        std::cout << "Invalid dimensions.\n";
        return;
    }

    Matrix features(Matrix::Shape{rows, cols});
    std::cout << "Feature values:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            std::cout << "  x[" << i << "][" << j << "] = ";
            if (!(std::cin >> features[i][j]))
                return;
        }

    // One label per observation - the CSV path enforces the same invariant.
    Vector labels(rows);
    std::cout << "Labels (one per observation):\n";
    for (int i = 0; i < rows; i++) {
        std::cout << "  y[" << i << "] = ";
        if (!(std::cin >> labels[i]))
            return;
    }

    std::vector<std::string> names;
    names.reserve(cols);
    for (int j = 0; j < cols; j++)
        names.push_back("feature_" + std::to_string(j));

    sample = Sample(features, labels, names, "label");
    std::cout << "Entered " << rows << " observations x " << cols << " features.\n";
}

void Interface::loadFrom(const std::string &path) {
    try {
        const CsvParser parser(path);
        sample = parser.load();
        std::cout << "Loaded " << sample.observations() << " observations x "
                  << sample.featureCount() << " features from " << path << "\n";
    } catch (const std::exception &e) {
        std::cout << "Load failed: " << e.what() << "\n";
    }
}

void Interface::showSummary() const {
    std::cout << "\n";
    sample.describe(std::cout);
}

void Interface::rankFeatures() const {
    std::cout << "\n";
    sample.rankFeaturesByCorrelation(std::cout);
}

void Interface::standardizeSample() {
    if (sample.empty()) {
        std::cout << "No sample loaded.\n";
        return;
    }

    sample = sample.standardized();
    std::cout << "Features standardized (zero mean, unit variance).\n";
}

void Interface::printSample() const {
    std::cout << "\n" << sample;
}

void Interface::clearSample() {
    sample.clear();
    std::cout << "Sample cleared.\n";
}

void Interface::runDemo() const {
    showSummary();
    rankFeatures();
}

void Interface::run() {
    running = true;
    int choice = 0;

    while (running) {
        printMenu();
        if (!readChoice(choice)) {
            std::cout << "\n";
            break;
        }

        switch (choice) {
            case 1: loadSample(); break;
            case 2: enterSampleManually(); break;
            case 3: showSummary(); break;
            case 4: rankFeatures(); break;
            case 5: standardizeSample(); break;
            case 6: printSample(); break;
            case 7: clearSample(); break;
            case 0: running = false; break;
            default: std::cout << "Unknown option.\n"; break;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Interface &app) {
    os << "Session [" << (app.running ? "running" : "idle") << "] holding ";
    os << app.sample;   // chains into Sample's operator<<, which chains into Matrix and Vector
    return os;
}
