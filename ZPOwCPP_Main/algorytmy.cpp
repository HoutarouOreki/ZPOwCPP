#include "algorytmy.h"
#include <algorithm>
#include <string>
#include <math.h>

std::vector<double> Algorytmy::srednie(const std::vector<double> &sumy, const int iloscWierszy)
{
    std::vector<double> srednie;
    for (auto &suma : sumy)
    {
        srednie.emplace_back(suma / iloscWierszy);
    }
    return srednie;
}

std::vector<std::vector<double>> transponuj(const std::vector<std::vector<double>> &wejscie)
{
    std::vector<std::vector<double>> wyjscie(wejscie[0].size());
    for (unsigned int nrWierszu = 0; nrWierszu < wejscie.size(); nrWierszu++)
    {
        auto wiersz = wejscie[nrWierszu];
        for (unsigned int nrKolumny = 0; nrKolumny < wiersz.size(); nrKolumny++)
        {
            wyjscie[nrKolumny].push_back(wiersz[nrKolumny]);
        }
    }
    return wyjscie;
}

std::vector<double> Algorytmy::mediany(const std::vector<std::vector<double>> &wejscie)
{
    auto wejscieTransponowane = transponuj(wejscie);
    for (auto &kolumna : wejscieTransponowane)
    {
        sort(kolumna.begin(), kolumna.end(), std::greater<double>());
    }
    auto wejsciePosortowane = transponuj(wejscieTransponowane);
    // transpozycja dwa razy być może nie jest najefektywniejszą metodą
    // uzyskania posortowanych kolumn, ale nie płacą mi za to, więc...

    std::vector<double> mediany;
    if (wejsciePosortowane.size() % 2 == 1)
    {
        mediany = wejsciePosortowane[(wejsciePosortowane.size() / 2)];
    }
    else
    {
        auto wiersz1 = wejsciePosortowane[(wejsciePosortowane.size() / 2) - 1];
        mediany.resize(wiersz1.size(), 0);
        auto wiersz2 = wejsciePosortowane[(wejsciePosortowane.size() / 2)];
        transform(wiersz1.begin(), wiersz1.end(), wiersz2.begin(), mediany.begin(),
                  [](double a, double b)
        {
            return (a + b) / 2.0;
        });
    }
    return mediany;
}

std::vector<double> Algorytmy::odchyleniaStandardowe(const std::vector<std::vector<double> > &wejscie, const std::vector<double> &srednie)
{
    std::vector<double> sumy;
    sumy.resize(srednie.size(), 0);
    for (unsigned int nrWiersza = 0; nrWiersza < wejscie.size(); nrWiersza++)
    {
        auto wiersz = wejscie[nrWiersza];
        for (unsigned int nrKolumny = 0; nrKolumny < wiersz.size(); nrKolumny++)
        {
            auto nawias = wiersz[nrKolumny] - srednie[nrKolumny];
            sumy[nrKolumny] += nawias * nawias;
        }
    }

    auto n = wejscie.size();
    std::vector<double> odchyleniaStandardowe;
    for (auto &suma : sumy)
    {
        odchyleniaStandardowe.emplace_back(std::sqrt(suma / (n - 1)));
    }

    return odchyleniaStandardowe;
}
