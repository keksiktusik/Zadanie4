#include "matrix.h"

/*! /brief Funkcja Zwalniaj�ca pami��
* Funkcja ta zwalnia pami�� ca�ej tablicy z urzyciem warunkowej iteracji, warunkiem jest to �e zmienna data nie jest pusta
*/
void matrix::freeMemory() {
    if (data) {
        for (int i = 0; i < n; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

/*! /brief Funkcja zape�niaj�ca pami�� tablicy
* Funkcja zape�nia pami�� ca�ej tablicy z urzyciem iteracji,
kod jest powtarzany a� do osi�gni�cia limitu pami�ci przekazanego jako argument tej funkcji
*/
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

// Wstawianie warto�ci
matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        throw std::out_of_range("Index out of range");
    }
    data[x][y] = wartosc;
    return *this;
}

// Pobieranie warto�ci
int matrix::pokaz(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        throw std::out_of_range("Index out of range");
    }
    return data[x][y];
}

// Transponowanie macierzy
matrix& matrix::dowroc() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(data[i][j], data[j][i]);
        }
    }
    return *this;
}

// Losowanie warto�ci
matrix& matrix::losuj() {
    std::srand(std::time(nullptr));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = std::rand() % 10;
        }
    }
    return *this;
}

// Wypisanie macierzy
std::ostream& operator<<(std::ostream& os, const matrix& m) {
    for (int i = 0; i < m.n; ++i) {
        for (int j = 0; j < m.n; ++j) {
            os << m.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}