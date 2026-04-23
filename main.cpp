#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Interfata.h"


/*****
 *
 *
 *  main workflow of the app:
    user inputs a csv sample file whom he can apply different ML basic algorithms for educational purposes
    in an interactive manner;

    todo:
    -fix ostream operators -replace get() - DONE
    -sample data generation
    -testing.
    -[] operator overload for both vector and matrix;
    -continue parsecsv: it essentially takes a csv file as an input (using ifstream) and composes one vector and matrix
    objects with parsed data from said csv file; - DK IF COMPOSE OR INHERITANCE
    -csv to txt? / actually parsing the csv for normalized data
    - [...]
    -start implementing model class which will later be used for the ML algorithms

 *
 *
 *
 *****/




float* generateV1(int size) {
    float *v = new float[size];

    for (int i = 0; i < size; i++)
        v[i] = i & 1;

    return v;
}

float* generateV2(int size) {
    float *v = new float[size];

    for (int i = 0; i < size; i++)
        v[i] = i % 7;

    return v;
}

void outputV(float* v, int size) {
    for (int i = 0; i < size; i++)
        std::cout << v[i] << ' ';
    std::cout << '\n';
}

int getSize(int *v) {
    return false;
}

int main() {
    float size = 10; //std::cin >> size;
    float *v1_neobiect = generateV1(size);
    float *v2_neobiect = generateV2(size);
    outputV(v1_neobiect, size);
    outputV(v2_neobiect, size);


    Vector v_obiect(v1_neobiect, size);
    // std::cout << v_obiect;

    v_obiect.setInterval(v2_neobiect, 3, 6);
    // std::cout << v_obiect;

    //v_obiect.setInterval();

    Interfata I;
    I.decision();


    return 0;
}