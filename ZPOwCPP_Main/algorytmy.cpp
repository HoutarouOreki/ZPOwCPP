#include "algorytmy.h"
#include <algorithm>

std::vector<double> Algorytmy::srednie(const std::vector<double> &sumy, const int iloscWierszy)
{
    std::vector<double> srednie;
    transform(sumy.begin(), sumy.end(), srednie.begin(), [iloscWierszy](double suma)
    {
        return suma / iloscWierszy;
    });
    return srednie;
}
std::vector<double> Algorytmy::mediany(const std::vector<std::vector<double>> &wejscie)
{
    std::vector<double> mediany;
    if (wejscie.size() % 2 == 1)
    {
        auto srodkowyWiersz = wejscie[(wejscie.size() / 2)];
        transform(srodkowyWiersz.begin(), srodkowyWiersz.end(), mediany.begin(),
                  [](std::string liczba){return stod(liczba);});
    }
    else
    {
        auto wiersz1 = wejscie[1 + (wejscie.size() / 2)];
        auto wiersz2 = wejscie[1 + (wejscie.size() / 2) + 1];
        transform(wiersz1.begin(), wiersz1.end(), wiersz2.begin(), mediany.begin(),
                  [](double a, double b)
        {
            return (a + b) / 2.0;
        });
    }
    return mediany;
}
