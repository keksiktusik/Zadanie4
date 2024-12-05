#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

/**
 * @file matrix.h
 * @brief Deklaracja klasy \c matrix.
 *
 * Plik nag��wkowy zawiera deklaracj� klasy \c matrix, kt�ra umo�liwia dynamiczne zarz�dzanie
 * kwadratow� macierz� o wymiarach \c n x \c n. Klasa zawiera metody do manipulacji danymi,
 * takie jak wstawianie, pobieranie warto�ci, transpozycja, czy losowe wype�nianie.
 * W pliku znajduj� si� r�wnie� przeci��one operatory do pracy z macierzami.
 */

 /**
  * @class matrix
  * @brief Klasa reprezentuj�ca kwadratow� macierz o dynamicznie alokowanym rozmiarze.
  *
  * Klasa \c matrix umo�liwia:
  * - Dynamiczne zarz�dzanie pami�ci� dla macierzy.
  * - Manipulacj� warto�ciami w macierzy.
  * - Operacje matematyczne i logiczne.
  * - Tworzenie specjalnych uk�ad�w, takich jak macierze diagonalne.
  */
class matrix {
private:
<<<<<<< HEAD
    /// Rozmiar macierzy n x n
    int n;         
    /// Dynamiczna alokacja danych macierzy
    int** data;    
    /// Pomocnicza metoda do zwalniania pami�ci
    void freeMemory();  
    /// Pomocnicza metoda do alokacji pami�ci
    void allocateMemory(int size); 

public:
    /// Konstruktor domy�lny
    matrix();                     
    /// Konstruktor o wymiarach n x n
    matrix(int n);               
    /// Konstruktor z tabel� danych
    matrix(int n, int* t);       
    /// Konstruktor kopiuj�cy
    matrix(const matrix& m);       
    /// Destruktor
    ~matrix();                     

    /// Alokacja pami�ci
    matrix& alokuj(int n);         
    /// Wstawianie warto�ci
    matrix& wstaw(int x, int y, int wartosc); 
    /// Pobieranie warto�ci
    int pokaz(int x, int y);       
    /// Transponowanie macierzy
    matrix& dowroc();              
    /// Losowe wype�nienie macierzy
    matrix& losuj();              
    /// Losowe wype�nienie cz�ci macierzy
    matrix& losuj(int x);         
    /// Macierz diagonalna
    matrix& diagonalna(int* t);    
    /// Przek�tna przesuni�ta
    matrix& diagonalna_k(int k, int* t); 

    // Operatory
    /// Dodawanie macierzy
    matrix& operator+(matrix& m);  
    /// Mno�enie macierzy
    matrix& operator*(matrix& m);  
    /// Dodawanie liczby
    matrix& operator+(int a);      
    /// Mno�enie przez liczb�
    matrix& operator*(int a);      
    /// Por�wnanie r�wno�ci
    bool operator==(const matrix& m) const; 
    /// Por�wnanie wielko�ci
    bool operator>(const matrix& m) const;  
    /// Por�wnanie mniejszo�ci
    bool operator<(const matrix& m) const;  

    /// Wypisanie macierzy
    friend std::ostream& operator<<(std::ostream& os, const matrix& m); 
=======
    int n;         ///< Rozmiar macierzy \c n x \c n.
    int** data;    ///< Dynamicznie alokowana tablica dwuwymiarowa przechowuj�ca dane macierzy.

    /**
     * @brief Zwalnia dynamicznie alokowan� pami�� dla macierzy.
     */
    void freeMemory();

    /**
     * @brief Alokuje pami�� dla macierzy o podanym rozmiarze.
     * @param size Rozmiar macierzy (\c size x \c size).
     */
    void allocateMemory(int size);

public:
    /**
     * @brief Konstruktor domy�lny.
     * Tworzy pust� macierz.
     */
    matrix();

    /**
     * @brief Konstruktor tworz�cy macierz o zadanym rozmiarze.
     * @param n Rozmiar macierzy (\c n x \c n).
     */
    matrix(int n);

    /**
     * @brief Konstruktor inicjalizuj�cy macierz danymi z tablicy.
     * @param n Rozmiar macierzy (\c n x \c n).
     * @param t Tablica jednowymiarowa przechowuj�ca dane macierzy.
     */
    matrix(int n, int* t);

    /**
     * @brief Konstruktor kopiuj�cy.
     * Tworzy now� macierz na podstawie istniej�cej.
     * @param m Macierz do skopiowania.
     */
    matrix(const matrix& m);

    /**
     * @brief Destruktor.
     * Usuwa dynamicznie alokowan� pami��.
     */
    ~matrix();

    /**
     * @brief Alokuje pami�� dla macierzy o zadanym rozmiarze.
     * @param n Rozmiar macierzy (\c n x \c n).
     * @return Referencja do obiektu \c matrix.
     */
    matrix& alokuj(int n);

    /**
     * @brief Wstawia warto�� do okre�lonej kom�rki macierzy.
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @param wartosc Warto�� do wstawienia.
     * @return Referencja do obiektu \c matrix.
     * @throw std::out_of_range Je�li indeksy s� poza zakresem.
     */
    matrix& wstaw(int x, int y, int wartosc);

    /**
     * @brief Pobiera warto�� z okre�lonej kom�rki macierzy.
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @return Warto�� z kom�rki \c (x, y).
     * @throw std::out_of_range Je�li indeksy s� poza zakresem.
     */
    int pokaz(int x, int y);

    /**
     * @brief Transponuje macierz.
     * Zamienia wiersze z kolumnami.
     * @return Referencja do obiektu \c matrix.
     */
    matrix& dowroc();

    /**
     * @brief Wype�nia macierz losowymi warto�ciami.
     * @return Referencja do obiektu \c matrix.
     */
    matrix& losuj();

    /**
     * @brief Wype�nia cz�� macierzy losowymi warto�ciami.
     * @param x Liczba losowych warto�ci do wstawienia.
     * @return Referencja do obiektu \c matrix.
     */
    matrix& losuj(int x);

    /**
     * @brief Tworzy macierz diagonaln� na podstawie tablicy warto�ci.
     * @param t Tablica warto�ci do wstawienia na przek�tn�.
     * @return Referencja do obiektu \c matrix.
     */
    matrix& diagonalna(int* t);

    /**
     * @brief Tworzy macierz z przesuni�t� przek�tn�.
     * @param k Liczba okre�laj�ca przesuni�cie (ujemna, zero, dodatnia).
     * @param t Tablica warto�ci do wstawienia na przek�tn�.
     * @return Referencja do obiektu \c matrix.
     */
    matrix& diagonalna_k(int k, int* t);

    /// Operatory matematyczne

    /**
     * @brief Dodaje dwie macierze.
     * @param m Druga macierz.
     * @return Wynik dodawania jako nowy obiekt \c matrix.
     * @throw std::invalid_argument Je�li rozmiary macierzy s� r�ne.
     */
    matrix& operator+(matrix& m);

    /**
     * @brief Mno�y dwie macierze.
     * @param m Druga macierz.
     * @return Wynik mno�enia jako nowy obiekt \c matrix.
     * @throw std::invalid_argument Je�li rozmiary macierzy s� niezgodne.
     */
    matrix& operator*(matrix& m);

    /**
     * @brief Dodaje liczb� do wszystkich element�w macierzy.
     * @param a Liczba do dodania.
     * @return Wynik operacji jako nowy obiekt \c matrix.
     */
    matrix& operator+(int a);

    /**
     * @brief Mno�y wszystkie elementy macierzy przez liczb�.
     * @param a Liczba do mno�enia.
     * @return Wynik operacji jako nowy obiekt \c matrix.
     */
    matrix& operator*(int a);

    /**
     * @brief Por�wnuje, czy dwie macierze s� r�wne.
     * @param m Druga macierz.
     * @return \c true je�li macierze s� r�wne, \c false w przeciwnym razie.
     */
    bool operator==(const matrix& m) const;

    /**
     * @brief Por�wnuje, czy macierz jest wi�ksza od innej.
     * @param m Druga macierz.
     * @return \c true je�li macierz jest wi�ksza, \c false w przeciwnym razie.
     */
    bool operator>(const matrix& m) const;

    /**
     * @brief Por�wnuje, czy macierz jest mniejsza od innej.
     * @param m Druga macierz.
     * @return \c true je�li macierz jest mniejsza, \c false w przeciwnym razie.
     */
    bool operator<(const matrix& m) const;

    /**
     * @brief Wypisuje zawarto�� macierzy na strumie� wyj�ciowy.
     * @param os Strumie� wyj�ciowy.
     * @param m Macierz do wypisania.
     * @return Referencja do strumienia wyj�ciowego.
     */
    friend std::ostream& operator<<(std::ostream& os, const matrix& m);
>>>>>>> fc2100b (uzupełnienie komentarzy)
};

#endif