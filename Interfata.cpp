//
// Created by Tudoran Eduard on 27.03.2026.
//
#include <iostream>
#include "Interfata.h"

void Interfata::decision() {
    bool running = true;

    while (running) {
        int choice = 0;

        std::cout << "----------------------\n";
        std::cout << "1. AFISARE SAMPLE\n";
        std::cout << "2. INIT SAMPLE MANUAL\n";
        std::cout << "3. CLEAR SAMPLE\n";
        std::cout << "0. EXIT\n";
        std::cout << "----------------------\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                s.get();
                break;

            case 2: {
                if (s.check()) {
                    char rein = 'n';
                    std::cout << "SAMPLE DEJA INITIALIZAT\n";
                    std::cout << "DORESTI REINITIALIZARE? (y/n)\n";
                    std::cin >> rein;

                    if (rein != 'y' && rein != 'Y') {
                        break;
                    }
                }

                s.manuallyInit();
                break;
            }

            case 3:
                clear();
                break;

            case 0:
                running = false;
                break;

            default:
                std::cout << "OPTIUNE INVALIDA\n";
                break;
        }
    }
}


void Interfata::clear() {
    if (!s.check()) {
        std::cout << "SAMPLE NEINITIALIZAT\n";
        return;
    }

    s.clear();
    std::cout << "SAMPLE STERS\n";
}
