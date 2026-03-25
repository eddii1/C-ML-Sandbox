#include <iostream>
#include "Vector.h"
#include "Matrix.h"


/*****
 *
 *
 *  main workflow of the app:
    user inputs a csv sample file whom he can apply different ML basic algorithms for educational purposes
    in an interactive manner;

    todo:
    -fix ostream operators -replace get()
    -[] operator overload for both vector and matrix;
    -continue parsecsv: it essentially takes a csv file as an input (using ifstream) and composes one vector and matrix
    objects with parsed data from said csv file;
    -generate sample data function for easier debugging
    - [...]

    -start implementing model class which will later be used for the ML algorithms

 *
 *
 *
 */////




int* generateV(int size) {
    int *v = new int[size];

    for (int i = 0; i < size; i++)
        v[i] = i & 1;

    return v;
}

void outputV(int size, int* v) {
    for (int i = 0; i < size; i++)
        std::cout << v[i] << ' ';
    std::cout << '\n';
}

int getSize(int *v) {

}

int main() {
    int size = 10; //std::cin >> size;
    int *v = generateV(size);
    //Vector v3(v, size);
    //v3.get();
    std::cout << sizeof(v) << '\n';

    int size_= getSize(v);
    std::cout << "Size is: " << size_ << '\n';

    return 0;
}