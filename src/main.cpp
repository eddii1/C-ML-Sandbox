#include <iostream>
#include <string>

#include "Interface.h"

/**
 * Entry point.
 *
 *   ./ml_sandbox                   interactive menu
 *   ./ml_sandbox data/sample.csv   loads the dataset first, then opens the menu
 *   ./ml_sandbox --demo <csv>      loads, prints the summary and ranking, exits
 */
int main(int argc, char **argv) {
    const bool demo = (argc > 1 && std::string(argv[1]) == "--demo");
    const int pathArg = demo ? 2 : 1;

    if (demo && argc <= pathArg) {
        std::cout << "usage: ml_sandbox --demo <csv>\n";
        return 1;
    }

    Interface app = (argc > pathArg) ? Interface(argv[pathArg]) : Interface();

    if (demo) {
        app.runDemo();
        return 0;
    }

    app.run();
    return 0;
}
