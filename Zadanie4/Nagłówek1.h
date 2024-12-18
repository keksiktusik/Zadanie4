#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

class matrix {
private:
    int n;         // Rozmiar macierzy n x n
    int** data;    // Dynamiczna alokacja danych macierzy

    void freeMemory();  // Pomocnicza metoda do zwalniania pami�ci
    void allocateMemory(int size); // Pomocnicza metoda do alokacji pami�ci

public:
    matrix();                      // Konstruktor domy�lny
    matrix(int n);                 // Konstruktor o wymiarach n x n
    matrix(int n, int* t);         // Konstruktor z tabel� danych
    matrix(const matrix& m);       // Konstruktor kopiuj�cy
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