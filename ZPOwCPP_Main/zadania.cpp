#include "zadania.h"

void zadania::wczytajPlik(std::vector<std::vector<std::string> > &wierszeKomorek)
{
    wierszeKomorek.clear();

    std::string sciezka;
    std::ifstream plikReader;
    while (true)
    {
        sciezka = consoleUtilities::readLine("Podaj sciezke do pliku csv");
        plikReader = std::ifstream(sciezka);

        if (!plikReader.is_open())
        {
            std::cout << "Nie mozna odczytac pliku." << std::endl;
            continue;
        }

        break;
    }

    CsvParser csvParser(",");
    while (!plikReader.eof())
    {
        std::string linia;
        getline(plikReader, linia);
        if (linia.length() != 0)
        {
            wierszeKomorek.push_back(csvParser.parseLine(linia));
        }
    }

    std::cout << "Wczytano " << wierszeKomorek.size() << " wierszy" << std::endl;
}

void zadania::parametryStatystyczne(const std::vector<std::vector<std::string> > &wierszeKomorek)
{
    const int iloscKolumn = 6;

    std::vector<std::vector<double>> wierszeKomorekDouble;

    std::vector<double> sumy{0, 0, 0, 0, 0, 0};
    for (unsigned int nrWierszu = 1; nrWierszu < wierszeKomorek.size(); nrWierszu++)
    {
        auto wiersz = wierszeKomorek[nrWierszu];
        wierszeKomorekDouble.push_back(std::vector<double>());
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
    auto odchyleniaStandardowe = Algorytmy::odchyleniaStandardowe(wierszeKomorekDouble, srednie);

    std::vector<std::string> naglowki;
    for (int i = 0; i < iloscKolumn; i++)
    {
        naglowki.emplace_back(wierszeKomorek[0][i]);
    }

    std::cout << " kolumna |  srednia  |  mediana  |  std dev  " << std::endl
              << "---------+-----------+-----------+-----------" << std::endl;
    for (int nrKolumny = 0; nrKolumny < iloscKolumn; nrKolumny++)
    {
        std::string paddingSpaces = std::string(std::max((int)(8 - naglowki[nrKolumny].size()), 0), ' ');
        std::cout << paddingSpaces << naglowki[nrKolumny] << " | "
                  << (consoleUtilities::subOrOverString(srednie[nrKolumny], 9)) << " | "
                  << consoleUtilities::subOrOverString(mediany[nrKolumny], 9) << " | "
                  << consoleUtilities::subOrOverString(odchyleniaStandardowe[nrKolumny], 9)
                  << std::endl;
    }
    std::cout << "Ilosc wierszy: " << iloscWierszy << std::endl;
}

void zadania::odbiegajaceZ2(const std::vector<std::vector<std::string> > &wierszeKomorek)
{

}

void zadania::korelacjaKrzyzowa(const std::vector<std::vector<std::string> > &wierszeKomorek)
{

}
