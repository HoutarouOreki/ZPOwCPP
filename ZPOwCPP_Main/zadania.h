#ifndef ZADANIA_H
#define ZADANIA_H

#include <vector>
#include <string>
#include <fstream>
#include <consoleutilities.h>
#include <iostream>
#include <csvparser.h>
#include <algorytmy.h>

namespace zadania
{
    /// \brief Punkt 1
    /// \details Wczytanie pliku do pamięci
    /// (w postaci wektora lub podobnej struktury danych – można pokusić
    /// się o wektor obiektów lub wektor struktur)
    void wczytajTabelaCsv(std::vector<std::vector<std::string>> &wierszeKomorek);

    /// \brief Punkt 2
    /// \details Obliczenie parametrów statystycznych
    /// (średnia, mediana, odchylenie standardowe, liczba wierszy)
    /// na kolumnach X, Y, Z, N, E oraz Z2.
    void parametryStatystyczne(const std::vector<std::vector<std::string>> &wierszeKomorek);

    /// \brief Punkt 3
    /// \details Znalezienie i wyświetlenie wierszy, w których wartość w kolumnie Z2 odbiega od średniej
    /// wartości o wartość podaną przez użytkownika (np. użytkownik podaje 0.1 i znajdujemy wartości
    /// pomiędzy średnia-0.1 a średnia+0.1).
    void odbiegajaceZ2(const std::vector<std::vector<std::string>> &wierszeKomorek);

    /// \brief Punkt 4
    /// \details Obliczenie wartości korelacji krzyżowej (cross-correlation) pomiędzy wybranym numerem
    /// wiersza i kolejnymi 9 wierszami (łącznie 10 elementów) oraz 10 liczbami wczytywanymi z innego
    /// pliku tekstowego (prosty plik tekstowy – po jednej liczbie typu float w wierszu, 10 wierszy), na
    /// wybranej przez użytkownika kolumnie (X, Y, Z, N, E lub Z2).
    void korelacjaKrzyzowa(const std::vector<std::vector<std::string>> &wierszeKomorek);
}

#endif // ZADANIA_H
