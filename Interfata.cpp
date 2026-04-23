//
// Created by Tudoran Eduard on 27.03.2026.
//
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Interfata.h"

void Interfata::decision() {
    int choice = 0;
    std::cout << "----------------------\n";
    std::cout << "1. AFISARE SAMPLE\n";
    std::cout << "2. INIT SAMPLE\n";
    std::cout << "3.---------------------\n";

    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout<<"da1 \n";
            bool sem = s.v.check();
            if (sem)
                V.get();
            else
                std::cout << "SAMPLE NEINITIALIZAT\n";

        case 2:
            std::cout << "da2\n";
            sem = V.check();
            if (sem) {
                char rein[2];
                std::cout << "SAMPLE DEJA INITIALIZAT\n";
                std::cout << "DORESTI REINITIALIZARE?(y/n)\n";
                std::cin >> rein;
                if (strcmp(rein, "y") == 1) {
                    V.set(0, nullptr);
                }
            } else {
                std::cout << "WHATS YOUR INPUT FILENAME?\n";
                char filename[204];
                std::cin >> filename;
                Sample.parseCSV(filename);


            }

    }

}


void Interfata::clear() {
    int choice = 0;

}