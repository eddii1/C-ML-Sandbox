//
// Created by Tudoran Eduard on 28.03.2026.
//

#include "Sample.h"

void Sample::clear() {
    m.clear();
    v.clear();
}

bool Sample::check() {
    return (v.check() == 1 && m.check() == 1 ? true : false);
}

void Sample::manuallyInit(Matrix& m_, Vector& v_) {
    struct pair {
        int n, m;
    };

    pair sizem_;

    std::cout << "DATI MATRICE: \n";
    int n, m;
    std::cout << "N = "; std::cin >> n;
    std::cout << '\n';
    std::cout << "M = "; std::cin >> m;
    std::cout << '\n';

    sizem_.n = n;
    sizem_.m = m;

    //clear(m, sizem_);





}
