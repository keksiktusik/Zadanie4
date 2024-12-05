#include "matrix.h"

<<<<<<< HEAD
/*! /brief Funkcja Zwalniajπca pamiÍÊ
* Funkcja ta zwalnia pamiÍÊ ca≥ej tablicy z urzyciem warunkowej iteracji, warunkiem jest to øe zmienna data nie jest pusta
*/
=======
/**
 * @file matrix.cpp
 * @brief Implementacja metod klasy \c matrix.
 *
 * Plik zawiera definicje funkcji dla klasy \c matrix, takich jak:
 * - Dynamiczna alokacja i zwalnianie pamiÍci (\c allocateMemory(), \c freeMemory()).
 * - Konstruktor i destruktor klasy.
 * - Operacje na macierzy: wstawianie, pobieranie, transpozycja, losowanie wartoúci.
 * - Przeciπøony operator do wypisywania macierzy.
 */

 /// Pomocnicze funkcje

 /**
  * @brief Zwalnia dynamicznie alokowanπ pamiÍÊ dla macierzy.
  */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
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
/*! /brief Funkcja zape≥niajπca pamiÍÊ tablicy
* Funkcja zape≥nia pamiÍÊ ca≥ej tablicy z urzyciem iteracji,
kod jest powtarzany aø do osiπgniÍcia limitu pamiÍci przekazanego jako argument tej funkcji
*/
=======
/**
 * @brief Alokuje pamiÍÊ dla macierzy o podanym rozmiarze.
 * @param size Rozmiar macierzy (\c n x \c n).
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
void matrix::allocateMemory(int size) {
    freeMemory();
    n = size;
    data = new int* [n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n]();
    }
}

<<<<<<< HEAD
/*! /brief Konstruktor domyúlny
* Definicja konstruktora ktÛra jest urzywana jeøeli nie sπ przekazane øadne argumenty podczas wywo≥ania
*/ 
matrix::matrix() : n(0), data(nullptr) {}

/*! Konstruktor z rozmiarem
* Definicja konstruktora ktÛra jest urzywana jeøeli jest przekazany jeden argument n w wywo≥aniu klasy
*/
=======
/// Implementacja konstruktorÛw

/**
 * @brief Konstruktor domyúlny.
 * Tworzy pustπ macierz bez alokacji pamiÍci.
 */
matrix::matrix() : n(0), data(nullptr) {}

/**
 * @brief Konstruktor tworzπcy macierz o zadanym rozmiarze.
 * @param n Rozmiar macierzy (\c n x \c n).
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
matrix::matrix(int n) : n(n), data(nullptr) {
    allocateMemory(n);
}

<<<<<<< HEAD
/*! /brief Konstruktor z tabelπ
* Definicja konstruktora ktÛra jest urzywana jeøeli jest przekazany jeden argument typu int i wskaünik typu int,
jest on uøywany jeøeli jest przekazywana tabela w wywo≥aniu klasy
*/ 
=======
/**
 * @brief Konstruktor inicjalizujπcy macierz danymi z tabeli.
 * @param n Rozmiar macierzy (\c n x \c n).
 * @param t Tablica jednowymiarowa przechowujπca dane macierzy.
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
matrix::matrix(int n, int* t) : n(n), data(nullptr) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = t[i * n + j];
        }
    }
}

<<<<<<< HEAD
/*! /brief Konstruktor kopiujπcy
* Definicja konstruktora ktÛra jest urzywana jeøeli w argumencie jest przekazana osobna instancja klasy, w tym przypadku dane w niej zawarte sπ kopiowane do nowej instancji 
*/ 
=======
/**
 * @brief Konstruktor kopiujπcy.
 * Tworzy nowπ macierz jako kopiÍ istniejπcej.
 * @param m Macierz do skopiowania.
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
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
* Definicja destruktora klasy ktÛra wywo≥uje metode freeMemory
*/ 
=======

/**
 * @brief Destruktor.
 * Zwalnia dynamicznie alokowanπ pamiÍÊ.
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
matrix::~matrix() {
    freeMemory();
}

<<<<<<< HEAD
/*! /brief Alokacja pamiÍci
* metoda alokacji pamiÍci ktÛra wype≥nia tablice danymi poprzez iteracyjne wywo≥ywanie metody alocateMemory z argumentem rozmiaru
*/ 
=======
/// Operacje na macierzy

/**
 * @brief Alokuje pamiÍÊ dla macierzy o zadanym rozmiarze.
 * Jeúli pamiÍÊ jest juø zaalokowana, sprawdza rozmiar i alokuje ponownie, jeúli to konieczne.
 * @param size Rozmiar macierzy (\c n x \c n).
 * @return Referencja do obiektu \c matrix.
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
matrix& matrix::alokuj(int size) {
    if (!data || n != size) {
        allocateMemory(size);
    }
    return *this;
}

<<<<<<< HEAD
/*! /brief Wstawianie wartoúci
* Metoda wstawiania przekazanej wartoúci pod wskazany index 
*/ 
=======
/**
 * @brief Wstawia wartoúÊ do okreúlonej komÛrki macierzy.
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @param wartosc WartoúÊ do wstawienia.
 * @return Referencja do obiektu \c matrix.
 * @throw std::out_of_range Jeúli podano indeks poza zakresem.
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        throw std::out_of_range("Index out of range");
    }
    data[x][y] = wartosc;
    return *this;
}

<<<<<<< HEAD
/*! /brief Pobieranie wartoúci
* Metoda zwracajπca wartoúÊ pod wskazanym indexem
*/ 
=======
/**
 * @brief Pobiera wartoúÊ z okreúlonej komÛrki macierzy.
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @return WartoúÊ w komÛrce \c (x, y).
 * @throw std::out_of_range Jeúli podano indeks poza zakresem.
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
int matrix::pokaz(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        throw std::out_of_range("Index out of range");
    }
    return data[x][y];
}

<<<<<<< HEAD
/*! /breif Odwrucenia macierzy 
* Metoda ktÛra przenosi wszystkie wartoúÊ zaposisane pod konkrentym indexami [i,j] tak by by≥y zapisane pod indexami [j, i]
*/
=======
/**
 * @brief Transponuje macierz.
 * Zamienia wiersze z kolumnami.
 * @return Referencja do obiektu \c matrix.
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
matrix& matrix::dowroc() {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::swap(data[i][j], data[j][i]);
        }
    }
    return *this;
}

<<<<<<< HEAD
/*! Losowanie wartoúci
* Metoda wype≥niania macierzy losowymi wartoúciami.
*/ 
=======
/**
 * @brief Wype≥nia macierz losowymi wartoúciami z zakresu 0-9.
 * @return Referencja do obiektu \c matrix.
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
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
* Metoda wypisania wartoúci macierzy.
*/ 
=======
/// Operatory

/**
 * @brief Operator wypisywania macierzy do strumienia.
 * @param os StrumieÒ wyjúciowy.
 * @param m Macierz do wypisania.
 * @return Referencja do strumienia wyjúciowego.
 */
>>>>>>> fc2100b (uzupe≈Çnienie komentarzy)
std::ostream& operator<<(std::ostream& os, const matrix& m) {
    for (int i = 0; i < m.n; ++i) {
        for (int j = 0; j < m.n; ++j) {
            os << m.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
