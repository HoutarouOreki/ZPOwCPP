#include "menu.h"
#include <zadania.h>

int main()
{
    std::vector<std::vector<std::string>> wierszeKomorek;

    Menu menu("Wybierz odpowiednia funkcje:");
    menu.addOption("Wczytaj plik do pamieci",
                   [&wierszeKomorek]() {zadania::wczytajPlik(wierszeKomorek);});
    menu.addOption("Oblicz parametry statystyczne",
                   [&wierszeKomorek]() {zadania::parametryStatystyczne(wierszeKomorek);});
    menu.addOption("Znalezienie i wyswietlenie wierszy, "
                   "w ktorych wartosc w kolumnie Z2 odbiega "
                   "od sredniej wartosci o podana wartosc",
                   [&wierszeKomorek]() {zadania::odbiegajaceZ2(wierszeKomorek);});
    menu.addOption("Obliczenie wartosci korelacji krzyzowej",
                   [&wierszeKomorek]() {zadania::korelacjaKrzyzowa(wierszeKomorek);});

    menu.run();
    return 0;
}
