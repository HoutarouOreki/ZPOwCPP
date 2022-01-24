#ifndef ALGORYTMY_H
#define ALGORYTMY_H

#include <vector>

namespace Algorytmy
{
    ///
    /// \brief Oblicza średnie dla kolumn na podstawie ich sum.
    /// \param sumy Sumy kolumn.
    /// \param iloscWierszy Ile wierszy ma każda kolumna.
    /// \return Średnie każdej kolumny.
    ///
    std::vector<double> srednie(const std::vector<double> &sumy, const int iloscWierszy);

    ///
    /// \brief Zwraca środkową lub średnią dwóch środkowych wartości.
    /// \param wejscie Wiersze z komórkami
    /// \return Mediany każdej kolumny.
    ///
    std::vector<double> mediany(const std::vector<std::vector<double> > &wejscie);

    ///
    /// \brief Oblicza odchylenie standardowe dla kolumn.
    /// \param wejscie Wiersze z komórkami.
    /// \param srednie Wcześniej obliczone średnie.
    /// \return Odchylenia standardowe każdej kolumny.
    ///
    std::vector<double> odchyleniaStandardowe(const std::vector<std::vector<double>> &wejscie, const std::vector<double> &srednie);

    ///
    /// \brief Oblicza współczynnik korelacji krzyżowej dla dwóch zestawów liczb.
    /// \param x
    /// \param y
    ///
    double wspolczynnikKorelacjiKrzyzowej(const std::vector<double> &x, const std::vector<double> &y);
};

#endif // ALGORYTMY_H
