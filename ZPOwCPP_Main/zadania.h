#ifndef ZADANIA_H
#define ZADANIA_H

#include <vector>
#include <string>
#include <fstream>
#include <consoleutilities.h>
#include <iostream>
#include <csvparser.h>
#include <algorytmy.h>

namespace zadania
{
    /// \brief Punkt 1
    void wczytajTabelaCsv(std::vector<std::vector<std::string>> &wierszeKomorek);

    /// \brief Punkt 2
    void parametryStatystyczne(const std::vector<std::vector<std::string>> &wierszeKomorek);

    /// \brief Punkt 3
    void odbiegajaceZ2(const std::vector<std::vector<std::string>> &wierszeKomorek);

    /// \brief Punkt 4
    void korelacjaKrzyzowa(const std::vector<std::vector<std::string>> &wierszeKomorek);
}

#endif // ZADANIA_H
