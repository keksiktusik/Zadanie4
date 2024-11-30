#include "matrix.h"

// Pomocnicze funkcje
void matrix::freeMemory() {
    if (data) {
        for (int i = 0; i < n; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

void matrix::allocateMemory(int size) {
    freeMemory();
    n = size;
    data = new int* [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n]();
    }
}

// Konstruktor domy�lny
matrix::matrix() : n(0), data(nullptr) {}

// Konstruktor z rozmiarem
matrix::matrix(int n) : n(n), data(nullptr) {
    allocateMemory(n);
}

// Konstruktor z tabel�
matrix::matrix(int n, int* t) : n(n), data(nullptr) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = t[i * n + j];
        }
    }
}

// Konstruktor kopiuj�cy
matrix::matrix(const matrix& m) : n(m.n), data(nullptr) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}
// Destruktor
matrix::~matrix() {
    freeMemory();
}

// Alokacja pami�ci
matrix& matrix::alokuj(int size) {
    if (!data || n != size) {
        allocateMemory(size);
    }
    return *this;
}