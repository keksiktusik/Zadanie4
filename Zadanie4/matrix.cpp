#include "matrix.h"


/**
 * @file matrix.cpp
 * @brief Implementacja metod klasy \c matrix.
 *
 * Plik zawiera definicje funkcji dla klasy \c matrix, takich jak:
 * - Dynamiczna alokacja i zwalnianie pamiêci (\c allocateMemory(), \c freeMemory()).
 * - Konstruktor i destruktor klasy.
 * - Operacje na macierzy: wstawianie, pobieranie, transpozycja, losowanie wartoœci.
 * - Przeci¹¿ony operator do wypisywania macierzy.
 */

 /// Pomocnicze funkcje

 /**
  * @brief Zwalnia dynamicznie alokowan¹ pamiêæ dla macierzy.
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
 * @brief Alokuje pamiêæ dla macierzy o podanym rozmiarze.
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


/// Implementacja konstruktorów

/**
 * @brief Konstruktor domyœlny.
 * Tworzy pust¹ macierz bez alokacji pamiêci.
 */
matrix::matrix() : n(0), data(nullptr) {}

/**
 * @brief Konstruktor tworz¹cy macierz o zadanym rozmiarze.
 * @param n Rozmiar macierzy (\c n x \c n).
 */
matrix::matrix(int n) : n(n), data(nullptr) {
    allocateMemory(n);
}

/**
 * @brief Konstruktor inicjalizuj¹cy macierz danymi z tabeli.
 * @param n Rozmiar macierzy (\c n x \c n).
 * @param t Tablica jednowymiarowa przechowuj¹ca dane macierzy.
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
 * @brief Konstruktor kopiuj¹cy.
 * Tworzy now¹ macierz jako kopiê istniej¹cej.
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
 * Zwalnia dynamicznie alokowan¹ pamiêæ.
 */
matrix::~matrix() {
    freeMemory();
}

/// Operacje na macierzy

/**
 * @brief Alokuje pamiêæ dla macierzy o zadanym rozmiarze.
 * Jeœli pamiêæ jest ju¿ zaalokowana, sprawdza rozmiar i alokuje ponownie, jeœli to konieczne.
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
 * @brief Wstawia wartoœæ do okreœlonej komórki macierzy.
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @param wartosc Wartoœæ do wstawienia.
 * @return Referencja do obiektu \c matrix.
 * @throw std::out_of_range Jeœli podano indeks poza zakresem.
 */
matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        throw std::out_of_range("Index out of range");
    }
    data[x][y] = wartosc;
    return *this;
}

/**
 * @brief Pobiera wartoœæ z okreœlonej komórki macierzy.
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @return Wartoœæ w komórce \c (x, y).
 * @throw std::out_of_range Jeœli podano indeks poza zakresem.
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
 * @brief Wype³nia macierz losowymi wartoœciami z zakresu 0-9.
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
 * @param os Strumieñ wyjœciowy.
 * @param m Macierz do wypisania.
 * @return Referencja do strumienia wyjœciowego.
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
