#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

///
/// \brief Klasa reprezentująca menu wyboru opcji.
///
class Menu
{
private:
    struct option
    {
        std::string title;
        void (*function)();

        option(const std::string& title, void (*&function)());
    };
    std::vector<option> options;
    std::string promptText;
    std::string exitOptionText;
    void printPromptAndOptions() const;
    void printOptions() const;

public:
    /// \brief Tworzy menu z ustalonym tekstem
    /// wyświetlanym obok zestawu opcji.
    Menu(const std::string& promptText);

    /// \brief Dodaje nową opcję do menu.
    /// \param[in] function Funkcja, która zostanie uruchomiona
    /// po wybraniu tej opcji.
    void addOption(const std::string& title, void ( *function)());

    /// \brief Uruchamia menu - wyświetla dostępne opcje
    /// a następnie czeka na wybór użytkownika i uruchamia
    /// funkcję wybranej opcji.
    void run() const;

    /// \brief Zwraca nazwę opcji wyjścia z menu.
    const std::string &getExitOptionText() const;

    /// \brief Ustawia nazwę opcji wyjścia z menu.
    /// \param[in] newExitOptionText
    void setExitOptionText(const std::string &newExitOptionText);

    /// \brief Zwraca tekst wyświetlany przy opcjach.
    const std::string &getPromptText() const;

    /// \brief Ustawia tekst wyświetlany przy opcjach.
    void setPromptText(const std::string &newPromptText);
};

#endif // MENU_H
