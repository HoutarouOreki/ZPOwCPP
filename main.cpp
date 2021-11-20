#include <iostream>
#include "menu.h"

using namespace std;

/// \brief Punkt 1
void wczytajPlik(){}

/// \brief Punkt 2
void parametryStatystyczne(){}

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
