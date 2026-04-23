//
// Created by Tudoran Eduard on 28.03.2026.
//

#include "Sample.h"

void Sample::clear() {
    m.clear();
    v.clear();
}

bool Sample::check() const {
    return m.check() && v.check();
}

void Sample::get() const {
    if (!check()) {
        std::cout << "SAMPLE NEINITIALIZAT\n";
        return;
    }

    std::cout << "MATRICE:\n";
    m.get();
    std::cout << "VECTOR:\n";
    v.get();
}

void Sample::manuallyInit() {
    int n = 0;
    int cols = 0;

    std::cout << "DATI MATRICE:\n";
    std::cout << "N = ";
    std::cin >> n;
    std::cout << "M = ";
    std::cin >> cols;

    if (n <= 0 || cols <= 0) {
        std::cout << "DIMENSIUNI INVALIDe\n";
        return;
    }

    float **tempMatrix = new float*[n];
    for (int i = 0; i < n; i++) {
        tempMatrix[i] = new float[cols];
    }

    std::cout << "ELEMENTELE MATRICEI:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "m[" << i << "][" << j << "] = ";
            std::cin >> tempMatrix[i][j];
        }
    }

    int vectorSize = 0;
    std::cout << "DIMENSIUNE VECTOR = ";
    std::cin >> vectorSize;

    if (vectorSize != n) {
        for (int i = 0; i < n; i++) {
            delete[] tempMatrix[i];
        }
        delete[] tempMatrix;

        std::cout << "VECTORUL TREBUIE SA AIBA DIMENSIUNEA " << n << "\n";
        return;
    }

    float *tempVector = new float[vectorSize];
    std::cout << "ELEMENTELE VECTORULUI:\n";
    for (int i = 0; i < vectorSize; i++) {
        std::cout << "v[" << i << "] = ";
        std::cin >> tempVector[i];
    }

    clear();

    Matrix::pair sizeMatrix;
    sizeMatrix.n = n;
    sizeMatrix.m = cols;

    m.set(tempMatrix, sizeMatrix);
    v.set(vectorSize, tempVector);

    for (int i = 0; i < n; i++) {
        delete[] tempMatrix[i];
    }
    delete[] tempMatrix;
    delete[] tempVector;
}
