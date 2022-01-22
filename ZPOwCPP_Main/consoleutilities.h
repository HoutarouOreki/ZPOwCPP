#ifndef CONSOLEUTILITIES_H
#define CONSOLEUTILITIES_H

#include <string>
#include <iostream>

namespace consoleUtilities
{
    template <typename T>
    T readNumber(const std::string& promptText = "")
    {
        std::string rawInput;
        T input;
        while (true) {
            if (promptText.length() > 0) {
                std::cout << promptText << std::endl;
            }
            std::cout << ">";
            std::cin >> rawInput;
            try {
                input = (T)stod(rawInput);
            } catch (const std::invalid_argument&) {
                std::cout << "The provided input is not a valid number." << std::endl;
                continue;
            } catch (const std::out_of_range&) {
                std::cout << "The provided input is not a valid number or it is too big." << std::endl;
                continue;
            }

            return input;
        }
    }

    int readIntMinMax(const int& min, const int& max, const std::string &promptText = "");
    std::string readLine(const std::string &promptText = "");

    std::string subOrOverString(const double d, const unsigned int n);
    std::string subOrOverString(const std::string s, const unsigned int n);
};

#endif // CONSOLEUTILITIES_H
