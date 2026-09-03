#ifndef ML_SANDBOX_INTERFACE_H
#define ML_SANDBOX_INTERFACE_H

#include <string>

#include "Sample.h"

/**
 * Interactive text menu over a single loaded Sample.
 *
 * Owns the session state and is the only class that talks to std::cin, which
 * keeps the container and parsing classes free of I/O concerns.
 */
class Interface {
    Sample sample;
    bool running;

    void printMenu() const;
    void loadSample();
    void enterSampleManually();
    void showSummary() const;
    void rankFeatures() const;
    void standardizeSample();
    void printSample() const;
    void clearSample();

    // Reads one menu selection; returns false on EOF.
    bool readChoice(int &choice) const;

public:
    Interface();

    // Loads `path` immediately, so a session can start from the command line.
    explicit Interface(const std::string &path);

    // Runs the menu loop until the user quits or stdin closes.
    void run();

    // Loads a dataset without prompting - used for the non-interactive demo.
    void loadFrom(const std::string &path);

    // Prints the summary and the feature ranking, then returns. No input read.
    void runDemo() const;

    friend std::ostream &operator<<(std::ostream &os, const Interface &app);
};

#endif //ML_SANDBOX_INTERFACE_H
