#include "zadania.h"
#include <functional>

bool sprawdzWczytanieWierszy(const std::vector<std::vector<std::string>> &wierszeKomorek)
{
    if (wierszeKomorek.empty())
    {
        std::cout << "Nie wczytano danych." << std::endl;
        return false;
    }
    return true;
}

void zadania::wczytajTabelaCsv(std::vector<std::vector<std::string> > &wierszeKomorek)
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
    if (!sprawdzWczytanieWierszy(wierszeKomorek)) return;

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
                  << consoleUtilities::subOrOverString(srednie[nrKolumny], 9) << " | "
                  << consoleUtilities::subOrOverString(mediany[nrKolumny], 9) << " | "
                  << consoleUtilities::subOrOverString(odchyleniaStandardowe[nrKolumny], 9)
                  << std::endl;
    }
    std::cout << "Ilosc wierszy: " << iloscWierszy << std::endl;
}

void zadania::odbiegajaceZ2(const std::vector<std::vector<std::string> > &wierszeKomorek)
{
    if (!sprawdzWczytanieWierszy(wierszeKomorek)) return;

    const int odrzucanePraweKolumny = 3;

    auto kolZ2 = [&wierszeKomorek](unsigned int indeks)
    {
        return std::stod(wierszeKomorek[indeks][5]);
    };

    double suma = 0;
    double min, max;
    min = max = kolZ2(1);
    for (unsigned int i = 1; i < wierszeKomorek.size(); i++)
    {
        auto v = kolZ2(i);
        suma += v;
        min = std::min(min, v);
        max = std::max(max, v);
    }
    auto srednia = suma / (wierszeKomorek.size() - 1);

    double maxRoznica = consoleUtilities::readNumber<double>("Podaj odleglosc od sredniej kolumny Z2, znalezione zostana wiersze spoza tego promienia\n"
            "avg=" + std::to_string(srednia) + ", max=" + std::to_string(max) + ", min=" + std::to_string(min));

    auto czyOdbiega = [srednia, maxRoznica](const double wartosc)
    {
        return wartosc < (srednia - maxRoznica) || wartosc > (srednia + maxRoznica);
    };

    const std::vector<unsigned short> szerokosciKolumn {8, 8, 8, 8, 8, 8, 9, 9, 25};

    std::cout << "    #|";
    for (unsigned int i = 0; i < wierszeKomorek[0].size() - 1 - odrzucanePraweKolumny; i++)
    {
        std::cout << consoleUtilities::subOrOverString(wierszeKomorek[0][i], szerokosciKolumn[i]) << "|";
    }
    std::cout << consoleUtilities::subOrOverString(wierszeKomorek[0][8], szerokosciKolumn[8]) << std::endl;

    for (unsigned int i = 1; i < wierszeKomorek.size(); i++)
    {
        if (czyOdbiega(kolZ2(i)))
        {
            std::cout << consoleUtilities::subOrOverString(std::to_string(i), 5) << "|";

            auto wiersz = wierszeKomorek[i];
            for (unsigned int j = 0; j < wiersz.size() - 1 - odrzucanePraweKolumny; j++)
            {
                std::cout << consoleUtilities::subOrOverString(wiersz[j], szerokosciKolumn[j]) << "|";
            }
            std::cout << consoleUtilities::subOrOverString(wiersz[8], szerokosciKolumn[8]) << std::endl;
        }
    }
}

std::vector<double> wczytajWierszowyPlik()
{
    std::vector<double> wiersze;

    std::string sciezka;
    std::ifstream plikReader;
    while (true)
    {
        sciezka = consoleUtilities::readLine("Podaj sciezke do pliku "
                                             "z 10 liczbami, kazda w innym wierszu.");
        plikReader = std::ifstream(sciezka);

        if (!plikReader.is_open())
        {
            std::cout << "Nie mozna odczytac pliku." << std::endl;
            continue;
        }

        break;
    }

    while (!plikReader.eof())
    {
        std::string linia;
        getline(plikReader, linia);
        if (linia.length() != 0)
        {
            wiersze.push_back(std::stod(linia));
        }
    }

    return wiersze;
}

void zadania::korelacjaKrzyzowa(const std::vector<std::vector<std::string> > &wierszeKomorek)
{
    if (!sprawdzWczytanieWierszy(wierszeKomorek)) return;

    if (wierszeKomorek.size() < 11)
    {
        std::cout << "Wczytane dane maja mniej niz 10 wierszy liczbowych." << std::endl
                  << "Nie mozna przejsc dalej." << std::endl;
    }

    std::cout << "Wybierz indeks wiersza dla korelacji krzyzowej.\n"
              << "Wziete zostana ten wiersz i 9 kolejnych.\n"
              << "Wiersz o indeksie 1 to pierwszy wiersz z wartosciami liczbowymi."
              << std::endl;
    int wybranyWiersz = consoleUtilities::readIntMinMax(1, wierszeKomorek.size() - 10);

    std::cout << "Wybierz kolumne:\n"
              << "0 = X\n"
              << "1 = Y\n"
              << "2 = Z\n"
              << "3 = N\n"
              << "4 = E\n"
              << "5 = Z2" << std::endl;
    int wybranaKolumna = consoleUtilities::readIntMinMax(0, 5);

    std::vector<double> x;
    std::cout << "Wybrane wartosci x: ";
    for (int i = wybranyWiersz; i < wybranyWiersz + 10; i++)
    {
        x.emplace_back(std::stod(wierszeKomorek[i][wybranaKolumna]));
        std::cout << x.at(i - wybranyWiersz) << " ";
    }
    std::cout << std::endl;

    std::vector<double> y;
    while (true)
    {
        y = wczytajWierszowyPlik();

        if (y.size() != 10)
        {
            std::cout << "Plik ma " << y.size() << " wierszy, zamiast 10. Sprobuj ponownie." << std::endl;
            continue;
        }

        break;
    }
    std::cout << "Wybrane wartosci y: ";
    for (auto &yi : y)
    {
        std::cout << yi << " ";
    }
    std::cout << std::endl;

    std::cout << "Wspolczynnik korelacji krzyzowej: " << Algorytmy::korelacjaKrzyzowa(x, y) << std::endl;
}
