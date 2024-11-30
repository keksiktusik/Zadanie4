#include "matrix.h"

/*! /brief Funkcja Zwalniaj¹ca pamiêæ
* Funkcja ta zwalnia pamiêæ ca³ej tablicy z urzyciem warunkowej iteracji, warunkiem jest to ¿e zmienna data nie jest pusta
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

/*! /brief Funkcja zape³niaj¹ca pamiêæ tablicy
* Funkcja zape³nia pamiêæ ca³ej tablicy z urzyciem iteracji,
kod jest powtarzany a¿ do osi¹gniêcia limitu pamiêci przekazanego jako argument tej funkcji
*/
void matrix::allocateMemory(int size) {
    freeMemory();
    n = size;
    data = new int* [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n]();
    }
}

/*! /brief Konstruktor domyœlny
* Definicja konstruktora która jest urzywana je¿eli nie s¹ przekazane ¿adne argumenty podczas wywo³ania
*/ 
matrix::matrix() : n(0), data(nullptr) {}

/*! Konstruktor z rozmiarem
* Definicja konstruktora która jest urzywana je¿eli jest przekazany jeden argument n w wywo³aniu klasy
*/
matrix::matrix(int n) : n(n), data(nullptr) {
    allocateMemory(n);
}

/*! Konstruktor z tabel¹
* Definicja konstruktora która jest urzywana je¿eli jest przekazany jeden argument typu int i wskaŸnik typu int,
jest on u¿ywany je¿eli jest przekazywana tabela w wywo³aniu klasy
*/ 
matrix::matrix(int n, int* t) : n(n), data(nullptr) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = t[i * n + j];
        }
    }
}

/*! Konstruktor kopiuj¹cy
* Definicja konstruktora która jest urzywana je¿eli w argumencie jest przekazana osobna instancja klasy, w tym przypadku dane w niej zawarte s¹ kopiowane do nowej instancji 
*/ 
matrix::matrix(const matrix& m) : n(m.n), data(nullptr) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}
/*! Destruktor
* Definicja destruktora klasy która wywo³uje metode freeMemory
*/ 
matrix::~matrix() {
    freeMemory();
}

// Alokacja pamiêci
matrix& matrix::alokuj(int size) {
    if (!data || n != size) {
        allocateMemory(size);
    }
    return *this;
}

// Wstawianie wartoœci
matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        throw std::out_of_range("Index out of range");
    }
    data[x][y] = wartosc;
    return *this;
}

// Pobieranie wartoœci
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

// Losowanie wartoœci
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