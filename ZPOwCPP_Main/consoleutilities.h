#ifndef CONSOLEUTILITIES_H
#define CONSOLEUTILITIES_H

#include <string>

namespace consoleUtilities
{
    int readInt(const std::string &promptText = "");
    int readIntMinMax(const int& min, const int& max, const std::string &promptText = "");
    std::string readLine(const std::string &promptText = "");

    std::string subOrOverString(const double d, const unsigned int n);
};

#endif // CONSOLEUTILITIES_H
