#include <iostream>
#include "matrix.h"

int main() {
    int size = 4;
    int table[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    matrix m1(size, table);
    std::cout << "Macierz m1:\n" << m1;

    m1.dowroc();
    std::cout << "\nMacierz transponowana m1:\n" << m1;

    m1.losuj();
    std::cout << "\nMacierz losowa m1:\n" << m1;


    return 0;
}