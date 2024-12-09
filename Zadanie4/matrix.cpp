#include "matrix.h"


/**
 * @file matrix.cpp
 * @brief Implementacja metod klasy \c matrix.
 *
 * Plik zawiera definicje funkcji dla klasy \c matrix, takich jak:
 * - Dynamiczna alokacja i zwalnianie pami�ci (\c allocateMemory(), \c freeMemory()).
 * - Konstruktor i destruktor klasy.
 * - Operacje na macierzy: wstawianie, pobieranie, transpozycja, losowanie warto�ci.
 * - Przeci��ony operator do wypisywania macierzy.
 */

 /// Pomocnicze funkcje

 /**
  * @brief Zwalnia dynamicznie alokowan� pami�� dla macierzy.
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


/**
 * @brief Alokuje pami�� dla macierzy o podanym rozmiarze.
 * @param size Rozmiar macierzy (\c n x \c n).
 */
void matrix::allocateMemory(int size) {
    freeMemory();
    n = size;
    data = new int* [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n]();
    }
}


/// Implementacja konstruktor�w

/**
 * @brief Konstruktor domy�lny.
 * Tworzy pust� macierz bez alokacji pami�ci.
 */
matrix::matrix() : n(0), data(nullptr) {}

/**
 * @brief Konstruktor tworz�cy macierz o zadanym rozmiarze.
 * @param n Rozmiar macierzy (\c n x \c n).
 */
matrix::matrix(int n) : n(n), data(nullptr) {
    allocateMemory(n);
}

/**
 * @brief Konstruktor inicjalizuj�cy macierz danymi z tabeli.
 * @param n Rozmiar macierzy (\c n x \c n).
 * @param t Tablica jednowymiarowa przechowuj�ca dane macierzy.
 */
matrix::matrix(int n, int* t) : n(n), data(nullptr) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = t[i * n + j];
        }
    }
}

/**
 * @brief Konstruktor kopiuj�cy.
 * Tworzy now� macierz jako kopi� istniej�cej.
 * @param m Macierz do skopiowania.
 */
matrix::matrix(const matrix& m) : n(m.n), data(nullptr) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

/**
 * @brief Destruktor.
 * Zwalnia dynamicznie alokowan� pami��.
 */
matrix::~matrix() {
    freeMemory();
}

/// Operacje na macierzy

/**
 * @brief Alokuje pami�� dla macierzy o zadanym rozmiarze.
 * Je�li pami�� jest ju� zaalokowana, sprawdza rozmiar i alokuje ponownie, je�li to konieczne.
 * @param size Rozmiar macierzy (\c n x \c n).
 * @return Referencja do obiektu \c matrix.
 */
matrix& matrix::alokuj(int size) {
    if (!data || n != size) {
        allocateMemory(size);
    }
    return *this;
}

/**
 * @brief Wstawia warto�� do okre�lonej kom�rki macierzy.
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @param wartosc Warto�� do wstawienia.
 * @return Referencja do obiektu \c matrix.
 * @throw std::out_of_range Je�li podano indeks poza zakresem.
 */
matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        throw std::out_of_range("Index out of range");
    }
    data[x][y] = wartosc;
    return *this;
}

/**
 * @brief Pobiera warto�� z okre�lonej kom�rki macierzy.
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @return Warto�� w kom�rce \c (x, y).
 * @throw std::out_of_range Je�li podano indeks poza zakresem.
 */
int matrix::pokaz(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        throw std::out_of_range("Index out of range");
    }
    return data[x][y];
}

/**
 * @brief Transponuje macierz.
 * Zamienia wiersze z kolumnami.
 * @return Referencja do obiektu \c matrix.
 */
matrix& matrix::dowroc() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(data[i][j], data[j][i]);
        }
    }
    return *this;
}

/**
 * @brief Wype�nia macierz losowymi warto�ciami z zakresu 0-9.
 * @return Referencja do obiektu \c matrix.
 */
matrix& matrix::losuj() {
    std::srand(std::time(nullptr));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = std::rand() % 10;
        }
    }
    return *this;
}

/// Operatory

/**
 * @brief Operator wypisywania macierzy do strumienia.
 * @param os Strumie� wyj�ciowy.
 * @param m Macierz do wypisania.
 * @return Referencja do strumienia wyj�ciowego.
 */
std::ostream& operator<<(std::ostream& os, const matrix& m) {
    for (int i = 0; i < m.n; ++i) {
        for (int j = 0; j < m.n; ++j) {
            os << m.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
