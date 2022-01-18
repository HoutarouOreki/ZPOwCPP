#include "consoleutilities.h"
#include <iostream>

int consoleUtilities::readInt(const std::string& promptText)
{
    std::string rawInput;
    int input;
    while (true) {
        if (promptText.length() > 0) {
            std::cout << promptText << std::endl;
        }
        std::cout << ">";
        std::cin >> rawInput;
        try {
            input = stoi(rawInput);
        } catch (const std::invalid_argument&) {
            std::cout << "The provided input is not a valid integer." << std::endl;
            continue;
        } catch (const std::out_of_range&) {
            std::cout << "The provided input is not a valid integer or it is too big." << std::endl;
            continue;
        }

        return input;
    }
}

std::string consoleUtilities::readLine(const std::string& promptText)
{
    if (promptText.length() > 0) {
        std::cout << promptText << std::endl;
    }
    std::cout << ">";
    std::string input;
    std::cin.ignore();
    getline(std::cin, input);
    return input;
}

int consoleUtilities::readIntMinMax(const int &min, const int &max, const std::string &promptText)
{
    int value;
    do {
        value = readInt(promptText);
        if (value < min || value > max) {
            std::cout << "The value has to be inside the range <"
                      << min << ", " << max << ">." << std::endl;
        }
    } while (value < min || value > max);
    return value;
}
