#ifndef ALGORYTMY_H
#define ALGORYTMY_H

#include <vector>

namespace Algorytmy
{
    std::vector<double> srednie(const std::vector<double> &sumy, const int iloscWierszy);

    std::vector<double> mediany(const std::vector<std::vector<double> > &wejscie);

    std::vector<double> odchyleniaStandardowe(const std::vector<std::vector<double>> &wejscie, const std::vector<double> &srednie);

    double korelacjaKrzyzowa(const std::vector<double> &x, const std::vector<double> &y);
};

#endif // ALGORYTMY_H
