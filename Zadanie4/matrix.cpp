#include "matrix.h"

<<<<<<< HEAD
/*! /brief Funkcja Zwalniaj�ca pami��
* Funkcja ta zwalnia pami�� ca�ej tablicy z urzyciem warunkowej iteracji, warunkiem jest to �e zmienna data nie jest pusta
*/
=======
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
>>>>>>> fc2100b (uzupełnienie komentarzy)
void matrix::freeMemory() {
    if (data) {
        for (int i = 0; i < n; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

<<<<<<< HEAD
/*! /brief Funkcja zape�niaj�ca pami�� tablicy
* Funkcja zape�nia pami�� ca�ej tablicy z urzyciem iteracji,
kod jest powtarzany a� do osi�gni�cia limitu pami�ci przekazanego jako argument tej funkcji
*/
=======
/**
 * @brief Alokuje pami�� dla macierzy o podanym rozmiarze.
 * @param size Rozmiar macierzy (\c n x \c n).
 */
>>>>>>> fc2100b (uzupełnienie komentarzy)
void matrix::allocateMemory(int size) {
    freeMemory();
    n = size;
    data = new int* [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n]();
    }
}

<<<<<<< HEAD
/*! /brief Konstruktor domy�lny
* Definicja konstruktora kt�ra jest urzywana je�eli nie s� przekazane �adne argumenty podczas wywo�ania
*/ 
matrix::matrix() : n(0), data(nullptr) {}

/*! Konstruktor z rozmiarem
* Definicja konstruktora kt�ra jest urzywana je�eli jest przekazany jeden argument n w wywo�aniu klasy
*/
=======
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
>>>>>>> fc2100b (uzupełnienie komentarzy)
matrix::matrix(int n) : n(n), data(nullptr) {
    allocateMemory(n);
}

<<<<<<< HEAD
/*! /brief Konstruktor z tabel�
* Definicja konstruktora kt�ra jest urzywana je�eli jest przekazany jeden argument typu int i wska�nik typu int,
jest on u�ywany je�eli jest przekazywana tabela w wywo�aniu klasy
*/ 
=======
/**
 * @brief Konstruktor inicjalizuj�cy macierz danymi z tabeli.
 * @param n Rozmiar macierzy (\c n x \c n).
 * @param t Tablica jednowymiarowa przechowuj�ca dane macierzy.
 */
>>>>>>> fc2100b (uzupełnienie komentarzy)
matrix::matrix(int n, int* t) : n(n), data(nullptr) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = t[i * n + j];
        }
    }
}

<<<<<<< HEAD
/*! /brief Konstruktor kopiuj�cy
* Definicja konstruktora kt�ra jest urzywana je�eli w argumencie jest przekazana osobna instancja klasy, w tym przypadku dane w niej zawarte s� kopiowane do nowej instancji 
*/ 
=======
/**
 * @brief Konstruktor kopiuj�cy.
 * Tworzy now� macierz jako kopi� istniej�cej.
 * @param m Macierz do skopiowania.
 */
>>>>>>> fc2100b (uzupełnienie komentarzy)
matrix::matrix(const matrix& m) : n(m.n), data(nullptr) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}
<<<<<<< HEAD
/*! /brief Destruktor
* Definicja destruktora klasy kt�ra wywo�uje metode freeMemory
*/ 
=======

/**
 * @brief Destruktor.
 * Zwalnia dynamicznie alokowan� pami��.
 */
>>>>>>> fc2100b (uzupełnienie komentarzy)
matrix::~matrix() {
    freeMemory();
}

<<<<<<< HEAD
/*! /brief Alokacja pami�ci
* metoda alokacji pami�ci kt�ra wype�nia tablice danymi poprzez iteracyjne wywo�ywanie metody alocateMemory z argumentem rozmiaru
*/ 
=======
/// Operacje na macierzy

/**
 * @brief Alokuje pami�� dla macierzy o zadanym rozmiarze.
 * Je�li pami�� jest ju� zaalokowana, sprawdza rozmiar i alokuje ponownie, je�li to konieczne.
 * @param size Rozmiar macierzy (\c n x \c n).
 * @return Referencja do obiektu \c matrix.
 */
>>>>>>> fc2100b (uzupełnienie komentarzy)
matrix& matrix::alokuj(int size) {
    if (!data || n != size) {
        allocateMemory(size);
    }
    return *this;
}

<<<<<<< HEAD
/*! /brief Wstawianie warto�ci
* Metoda wstawiania przekazanej warto�ci pod wskazany index 
*/ 
=======
/**
 * @brief Wstawia warto�� do okre�lonej kom�rki macierzy.
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @param wartosc Warto�� do wstawienia.
 * @return Referencja do obiektu \c matrix.
 * @throw std::out_of_range Je�li podano indeks poza zakresem.
 */
>>>>>>> fc2100b (uzupełnienie komentarzy)
matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        throw std::out_of_range("Index out of range");
    }
    data[x][y] = wartosc;
    return *this;
}

<<<<<<< HEAD
/*! /brief Pobieranie warto�ci
* Metoda zwracaj�ca warto�� pod wskazanym indexem
*/ 
=======
/**
 * @brief Pobiera warto�� z okre�lonej kom�rki macierzy.
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @return Warto�� w kom�rce \c (x, y).
 * @throw std::out_of_range Je�li podano indeks poza zakresem.
 */
>>>>>>> fc2100b (uzupełnienie komentarzy)
int matrix::pokaz(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        throw std::out_of_range("Index out of range");
    }
    return data[x][y];
}

<<<<<<< HEAD
/*! /breif Odwrucenia macierzy 
* Metoda kt�ra przenosi wszystkie warto�� zaposisane pod konkrentym indexami [i,j] tak by by�y zapisane pod indexami [j, i]
*/
=======
/**
 * @brief Transponuje macierz.
 * Zamienia wiersze z kolumnami.
 * @return Referencja do obiektu \c matrix.
 */
>>>>>>> fc2100b (uzupełnienie komentarzy)
matrix& matrix::dowroc() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(data[i][j], data[j][i]);
        }
    }
    return *this;
}

<<<<<<< HEAD
/*! Losowanie warto�ci
* Metoda wype�niania macierzy losowymi warto�ciami.
*/ 
=======
/**
 * @brief Wype�nia macierz losowymi warto�ciami z zakresu 0-9.
 * @return Referencja do obiektu \c matrix.
 */
>>>>>>> fc2100b (uzupełnienie komentarzy)
matrix& matrix::losuj() {
    std::srand(std::time(nullptr));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = std::rand() % 10;
        }
    }
    return *this;
}

<<<<<<< HEAD
/*! Wypisanie macierzy
* Metoda wypisania warto�ci macierzy.
*/ 
=======
/// Operatory

/**
 * @brief Operator wypisywania macierzy do strumienia.
 * @param os Strumie� wyj�ciowy.
 * @param m Macierz do wypisania.
 * @return Referencja do strumienia wyj�ciowego.
 */
>>>>>>> fc2100b (uzupełnienie komentarzy)
std::ostream& operator<<(std::ostream& os, const matrix& m) {
    for (int i = 0; i < m.n; ++i) {
        for (int j = 0; j < m.n; ++j) {
            os << m.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
