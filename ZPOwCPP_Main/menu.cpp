#include "menu.h"
#include "consoleutilities.h"
#include <iostream>

const std::string &Menu::getExitOptionText() const
{
    return exitOptionText;
}

void Menu::setExitOptionText(const std::string &newExitOptionText)
{
    exitOptionText = newExitOptionText;
}

void Menu::addOption(const std::string title, void (*function)())
{
    options.push_back(option(title, function));
}

const std::string &Menu::getPromptText() const
{
    return promptText;
}

void Menu::setPromptText(const std::string &newPromptText)
{
    promptText = newPromptText;
}

void Menu::printPromptAndOptions() const
{
    std::cout << promptText << std::endl;
    printOptions();
}

void Menu::printOptions() const
{
    for (unsigned int i = 0; i < options.size(); i++) {
        std::cout << i + 1 << ". " << options.at(i).title << std::endl;
    }
    std::cout << "0. " << exitOptionText << std::endl;
}

Menu::Menu(const std::string &promptText)
{
    exitOptionText = "Exit";
    this->promptText = promptText;
}

void Menu::run() const
{
    while (true) {
        printPromptAndOptions();
        const int selectionIndex = consoleUtilities::readIntMinMax(0, options.size()) - 1;
        if (selectionIndex > -1) {
            options.at(selectionIndex).function();
        } else {
            break;
        }
    }
}

Menu::option::option(const std::string &title, void (*&function)())
{
    this->title = title;
    this->function = function;
}
