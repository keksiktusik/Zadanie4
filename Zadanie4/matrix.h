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
 * Plik nag³ówkowy zawiera deklaracjê klasy \c matrix, która umo¿liwia dynamiczne zarz¹dzanie
 * kwadratow¹ macierz¹ o wymiarach \c n x \c n. Klasa zawiera metody do manipulacji danymi,
 * takie jak wstawianie, pobieranie wartoœci, transpozycja, czy losowe wype³nianie.
 * W pliku znajduj¹ siê równie¿ przeci¹¿one operatory do pracy z macierzami.
 */

 /**
  * @class matrix
  * @brief Klasa reprezentuj¹ca kwadratow¹ macierz o dynamicznie alokowanym rozmiarze.
  *
  * Klasa \c matrix umo¿liwia:
  * - Dynamiczne zarz¹dzanie pamiêci¹ dla macierzy.
  * - Manipulacjê wartoœciami w macierzy.
  * - Operacje matematyczne i logiczne.
  * - Tworzenie specjalnych uk³adów, takich jak macierze diagonalne.
  */
class matrix {
private:
<<<<<<< HEAD
    /// Rozmiar macierzy n x n
    int n;         
    /// Dynamiczna alokacja danych macierzy
    int** data;    
    /// Pomocnicza metoda do zwalniania pamiêci
    void freeMemory();  
    /// Pomocnicza metoda do alokacji pamiêci
    void allocateMemory(int size); 

public:
    /// Konstruktor domyœlny
    matrix();                     
    /// Konstruktor o wymiarach n x n
    matrix(int n);               
    /// Konstruktor z tabel¹ danych
    matrix(int n, int* t);       
    /// Konstruktor kopiuj¹cy
    matrix(const matrix& m);       
    /// Destruktor
    ~matrix();                     

    /// Alokacja pamiêci
    matrix& alokuj(int n);         
    /// Wstawianie wartoœci
    matrix& wstaw(int x, int y, int wartosc); 
    /// Pobieranie wartoœci
    int pokaz(int x, int y);       
    /// Transponowanie macierzy
    matrix& dowroc();              
    /// Losowe wype³nienie macierzy
    matrix& losuj();              
    /// Losowe wype³nienie czêœci macierzy
    matrix& losuj(int x);         
    /// Macierz diagonalna
    matrix& diagonalna(int* t);    
    /// Przek¹tna przesuniêta
    matrix& diagonalna_k(int k, int* t); 

    // Operatory
    /// Dodawanie macierzy
    matrix& operator+(matrix& m);  
    /// Mno¿enie macierzy
    matrix& operator*(matrix& m);  
    /// Dodawanie liczby
    matrix& operator+(int a);      
    /// Mno¿enie przez liczbê
    matrix& operator*(int a);      
    /// Porównanie równoœci
    bool operator==(const matrix& m) const; 
    /// Porównanie wielkoœci
    bool operator>(const matrix& m) const;  
    /// Porównanie mniejszoœci
    bool operator<(const matrix& m) const;  

    /// Wypisanie macierzy
    friend std::ostream& operator<<(std::ostream& os, const matrix& m); 
=======
    int n;         ///< Rozmiar macierzy \c n x \c n.
    int** data;    ///< Dynamicznie alokowana tablica dwuwymiarowa przechowuj¹ca dane macierzy.

    /**
     * @brief Zwalnia dynamicznie alokowan¹ pamiêæ dla macierzy.
     */
    void freeMemory();

    /**
     * @brief Alokuje pamiêæ dla macierzy o podanym rozmiarze.
     * @param size Rozmiar macierzy (\c size x \c size).
     */
    void allocateMemory(int size);

public:
    /**
     * @brief Konstruktor domyœlny.
     * Tworzy pust¹ macierz.
     */
    matrix();

    /**
     * @brief Konstruktor tworz¹cy macierz o zadanym rozmiarze.
     * @param n Rozmiar macierzy (\c n x \c n).
     */
    matrix(int n);

    /**
     * @brief Konstruktor inicjalizuj¹cy macierz danymi z tablicy.
     * @param n Rozmiar macierzy (\c n x \c n).
     * @param t Tablica jednowymiarowa przechowuj¹ca dane macierzy.
     */
    matrix(int n, int* t);

    /**
     * @brief Konstruktor kopiuj¹cy.
     * Tworzy now¹ macierz na podstawie istniej¹cej.
     * @param m Macierz do skopiowania.
     */
    matrix(const matrix& m);

    /**
     * @brief Destruktor.
     * Usuwa dynamicznie alokowan¹ pamiêæ.
     */
    ~matrix();

    /**
     * @brief Alokuje pamiêæ dla macierzy o zadanym rozmiarze.
     * @param n Rozmiar macierzy (\c n x \c n).
     * @return Referencja do obiektu \c matrix.
     */
    matrix& alokuj(int n);

    /**
     * @brief Wstawia wartoœæ do okreœlonej komórki macierzy.
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @param wartosc Wartoœæ do wstawienia.
     * @return Referencja do obiektu \c matrix.
     * @throw std::out_of_range Jeœli indeksy s¹ poza zakresem.
     */
    matrix& wstaw(int x, int y, int wartosc);

    /**
     * @brief Pobiera wartoœæ z okreœlonej komórki macierzy.
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @return Wartoœæ z komórki \c (x, y).
     * @throw std::out_of_range Jeœli indeksy s¹ poza zakresem.
     */
    int pokaz(int x, int y);

    /**
     * @brief Transponuje macierz.
     * Zamienia wiersze z kolumnami.
     * @return Referencja do obiektu \c matrix.
     */
    matrix& dowroc();

    /**
     * @brief Wype³nia macierz losowymi wartoœciami.
     * @return Referencja do obiektu \c matrix.
     */
    matrix& losuj();

    /**
     * @brief Wype³nia czêœæ macierzy losowymi wartoœciami.
     * @param x Liczba losowych wartoœci do wstawienia.
     * @return Referencja do obiektu \c matrix.
     */
    matrix& losuj(int x);

    /**
     * @brief Tworzy macierz diagonaln¹ na podstawie tablicy wartoœci.
     * @param t Tablica wartoœci do wstawienia na przek¹tn¹.
     * @return Referencja do obiektu \c matrix.
     */
    matrix& diagonalna(int* t);

    /**
     * @brief Tworzy macierz z przesuniêt¹ przek¹tn¹.
     * @param k Liczba okreœlaj¹ca przesuniêcie (ujemna, zero, dodatnia).
     * @param t Tablica wartoœci do wstawienia na przek¹tn¹.
     * @return Referencja do obiektu \c matrix.
     */
    matrix& diagonalna_k(int k, int* t);

    /// Operatory matematyczne

    /**
     * @brief Dodaje dwie macierze.
     * @param m Druga macierz.
     * @return Wynik dodawania jako nowy obiekt \c matrix.
     * @throw std::invalid_argument Jeœli rozmiary macierzy s¹ ró¿ne.
     */
    matrix& operator+(matrix& m);

    /**
     * @brief Mno¿y dwie macierze.
     * @param m Druga macierz.
     * @return Wynik mno¿enia jako nowy obiekt \c matrix.
     * @throw std::invalid_argument Jeœli rozmiary macierzy s¹ niezgodne.
     */
    matrix& operator*(matrix& m);

    /**
     * @brief Dodaje liczbê do wszystkich elementów macierzy.
     * @param a Liczba do dodania.
     * @return Wynik operacji jako nowy obiekt \c matrix.
     */
    matrix& operator+(int a);

    /**
     * @brief Mno¿y wszystkie elementy macierzy przez liczbê.
     * @param a Liczba do mno¿enia.
     * @return Wynik operacji jako nowy obiekt \c matrix.
     */
    matrix& operator*(int a);

    /**
     * @brief Porównuje, czy dwie macierze s¹ równe.
     * @param m Druga macierz.
     * @return \c true jeœli macierze s¹ równe, \c false w przeciwnym razie.
     */
    bool operator==(const matrix& m) const;

    /**
     * @brief Porównuje, czy macierz jest wiêksza od innej.
     * @param m Druga macierz.
     * @return \c true jeœli macierz jest wiêksza, \c false w przeciwnym razie.
     */
    bool operator>(const matrix& m) const;

    /**
     * @brief Porównuje, czy macierz jest mniejsza od innej.
     * @param m Druga macierz.
     * @return \c true jeœli macierz jest mniejsza, \c false w przeciwnym razie.
     */
    bool operator<(const matrix& m) const;

    /**
     * @brief Wypisuje zawartoœæ macierzy na strumieñ wyjœciowy.
     * @param os Strumieñ wyjœciowy.
     * @param m Macierz do wypisania.
     * @return Referencja do strumienia wyjœciowego.
     */
    friend std::ostream& operator<<(std::ostream& os, const matrix& m);
>>>>>>> fc2100b (uzupeÅ‚nienie komentarzy)
};

#endif