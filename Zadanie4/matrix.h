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
    matrix& operator+(matrix& m);  // Dodawanie macierzy
    matrix& operator*(matrix& m);  // Mno¿enie macierzy
    matrix& operator+(int a);      // Dodawanie liczby
    matrix& operator*(int a);      // Mno¿enie przez liczbê
    bool operator==(const matrix& m) const; // Porównanie równoœci
    bool operator>(const matrix& m) const;  // Porównanie wielkoœci
    bool operator<(const matrix& m) const;  // Porównanie mniejszoœci

    friend std::ostream& operator<<(std::ostream& os, const matrix& m); // Wypisanie macierzy
};

#endif