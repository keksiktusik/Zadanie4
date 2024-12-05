/**
 * @file main.cpp
 * @brief Główny plik programu testującego klasę \c matrix.
 *
 * Plik zawiera funkcję \c main(), która testuje działanie klasy \c matrix.
 * Tworzone są różne przypadki użycia, w tym:
 * - Tworzenie macierzy na podstawie tabeli wartości.
 * - Transpozycja macierzy za pomocą metody \c dowroc().
 * - Wypełnianie macierzy losowymi wartościami za pomocą metody \c losuj().
 *
 * Dokumentacja zawiera przykłady użycia, generuje wykres wywołań oraz tabelę wyników.
 */
#include <iostream>
#include "matrix.h"
 /**
  * @brief Funkcja główna programu.
  *
  * Funkcja tworzy obiekt klasy \c matrix, a następnie wykonuje następujące operacje:
  * - Inicjalizacja macierzy o rozmiarze 4x4 z danymi z tablicy \c table.
  * - Wypisanie początkowej macierzy.
  * - Transpozycja macierzy za pomocą metody \c dowroc() i jej ponowne wypisanie.
  * - Losowe wypełnienie macierzy za pomocą metody \c losuj() i wypisanie wyników.
  *
  * @return Zwraca \c 0, jeśli program zakończył się poprawnie.
  */
int main() {
    int size = 4;///< Rozmiar macierzy (4x4).
    int table[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    /**
 * @brief Tworzenie obiektu macierzy na podstawie tablicy danych.
 */
    matrix m1(size, table);
    std::cout << "Macierz m1:\n" << m1;
    /**
       * @brief Transpozycja macierzy.
       */
    m1.dowroc();
    std::cout << "\nMacierz transponowana m1:\n" << m1;
    /**
    * @brief Wypełnienie macierzy losowymi wartościami.
    */
    m1.losuj();
    std::cout << "\nMacierz losowa m1:\n" << m1;


    return 0;
}