#include "consoleutilities.h"
#include <iostream>
#include <cwctype>

std::string consoleUtilities::readLine(const std::string& promptText)
{
    if (promptText.length() > 0) {
        std::cout << promptText << std::endl;
    }
    std::cout << ">";
    std::string input;
    if (std::iswspace(std::cin.peek())) std::cin.ignore();
    getline(std::cin, input);
    return input;
}

int consoleUtilities::readIntMinMax(const int &min, const int &max, const std::string &promptText)
{
    int value = 0;
    do {
        value = readNumber<int>(promptText);
        if (value < min || value > max) {
            std::cout << "The value has to be inside the range <"
                      << min << ", " << max << ">." << std::endl;
        }
    } while (value < min || value > max);
    return value;
}

std::string consoleUtilities::subOrOverString(const double d, const unsigned int n)
{
    auto s = std::to_string(d);
    return subOrOverString(s, n);
}

std::string consoleUtilities::subOrOverString(const std::string s, const unsigned int n)
{
    if (s.size() == n)
    {
        return s;
    }
    if (s.size() < n)
    {
        return std::string(n - s.size(), ' ') + s;
    }
    return s.substr(0, n);
}
