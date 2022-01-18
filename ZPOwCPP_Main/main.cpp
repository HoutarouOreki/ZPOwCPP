#include <iostream>
#include <fstream>
#include "menu.h"
#include "consoleutilities.h"
#include "csvparser.h"
#include "algorytmy.h"

using namespace std;

vector<vector<string>> wierszeKomorek;

/// \brief Punkt 1
void wczytajPlik()
{
    string sciezka;
    ifstream plikReader;
    while (true)
    {
        sciezka = consoleUtilities::readLine("Podaj sciezke do pliku csv");
        plikReader.open(sciezka);

        if (!plikReader.is_open())
        {
            cout << "Nie mozna odczytac pliku." << endl;
            continue;
        }

        break;
    }

    CsvParser csvParser(",");
    while (!plikReader.eof())
    {
        string linia;
        getline(plikReader, linia);
        wierszeKomorek.push_back(csvParser.parseLine(linia));
    }

    cout << "Wczytano " << wierszeKomorek.size() << " wierszy" << endl;
}

/// \brief Punkt 2
void parametryStatystyczne()
{
    const int iloscKolumn = 6;

    vector<vector<double>> wierszeKomorekDouble;

    vector<double> sumy{0, 0, 0, 0, 0, 0};
    for (unsigned int nrWierszu = 1; nrWierszu < wierszeKomorek.size(); nrWierszu++)
    {
        auto wiersz = wierszeKomorek[nrWierszu];
        wierszeKomorekDouble.push_back(vector<double>());
        for (unsigned int nrKolumny = 0; nrKolumny < iloscKolumn; nrKolumny++)
        {
            auto liczba = stod(wiersz[nrKolumny]);
            sumy[nrKolumny] += liczba;
            wierszeKomorekDouble.back().push_back(liczba);
        }
    }

    int iloscWierszy = wierszeKomorek.size() - 1;

    auto srednie = Algorytmy::srednie(sumy, iloscWierszy);
    auto mediany = Algorytmy::mediany(wierszeKomorekDouble);
    // todo tests
}

/// \brief Punkt 3
void odbiegajaceZ2(){}

/// \brief Punkt 4
void korelacjaKrzyzowa(){}

int main()
{
    Menu menu("Wybierz odpowiednia funkcje:");
    menu.addOption("Wczytaj plik do pamieci", wczytajPlik);
    menu.addOption("Oblicz parametry statystyczne", parametryStatystyczne);
    menu.addOption("Znalezienie i wyswietlenie wierszy, "
                   "w ktorych wartosc w kolumnie Z2 odbiega "
                   "od sredniej wartosci o podana wartosc", odbiegajaceZ2);
    menu.addOption("Obliczenie wartosci korelacji krzyzowej", korelacjaKrzyzowa);
    menu.run();
    return 0;
}
