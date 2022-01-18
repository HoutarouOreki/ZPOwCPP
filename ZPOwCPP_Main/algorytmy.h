#ifndef ALGORYTMY_H
#define ALGORYTMY_H

#include <vector>
#include <string>

namespace Algorytmy
{
    std::vector<double> srednie(const std::vector<double> &sumy, const int iloscWierszy);

    std::vector<double> mediany(const std::vector<std::vector<double>> &wejscie);
};

#endif // ALGORYTMY_H
