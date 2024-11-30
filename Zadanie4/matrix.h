#ifndef MATRIX_H
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

class matrix {
private:
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
    ~matrix();                     // Destruktor

    matrix& alokuj(int n);         // Alokacja pami�ci
    matrix& wstaw(int x, int y, int wartosc);  // Wstawianie warto�ci
    int pokaz(int x, int y);       // Pobieranie warto�ci
    matrix& dowroc();              // Transponowanie macierzy
    matrix& losuj();               // Losowe wype�nienie macierzy
    matrix& losuj(int x);          // Losowe wype�nienie cz�ci macierzy
    matrix& diagonalna(int* t);    // Macierz diagonalna
    matrix& diagonalna_k(int k, int* t); // Przek�tna przesuni�ta

    // Operatory
    matrix& operator+(matrix& m);  // Dodawanie macierzy
    matrix& operator*(matrix& m);  // Mno�enie macierzy
    matrix& operator+(int a);      // Dodawanie liczby
    matrix& operator*(int a);      // Mno�enie przez liczb�
    bool operator==(const matrix& m) const; // Por�wnanie r�wno�ci
    bool operator>(const matrix& m) const;  // Por�wnanie wielko�ci
    bool operator<(const matrix& m) const;  // Por�wnanie mniejszo�ci

    friend std::ostream& operator<<(std::ostream& os, const matrix& m); // Wypisanie macierzy
};

#endif