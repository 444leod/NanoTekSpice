/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Logger
*/

#include "Logger.hpp"
#include <cmath>

/**
 * @brief Logger class constructor
 * @details Has 10 input pins: 8 for the char, 1 for the clock and 1 for the inhibit
*/
Logger::Logger(std::string name) : AComponent(name)
{
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_INPUT},
        {4, CREATE_INPUT},
        {5, CREATE_INPUT},
        {6, CREATE_INPUT},
        {7, CREATE_INPUT},
        {8, CREATE_INPUT},
        {9, CREATE_INPUT},
        {10, CREATE_INPUT}
    };
}

/**
 * @brief Gets the char from the input pins
 * @return The char
*/
char Logger::getCharFromPins() {
    char result = 0;
    nts::Tristate state;

    for (int i = 0; i < 8; ++i) {
        state = _pins[i + 1]->getState();
        if (state == nts::Tristate::Undefined)
            return -1;
        if (state == nts::Tristate::True)
            result += std::pow(2, i);
    }
    return result;
}

/**
 * @brief Writes a char to a log.bin file
 * @param c The char to write
*/
void Logger::writeChar(char c) {
    std::ofstream file;

    if (c == -1)
        return;
    file.open("log.bin", std::ios::in | std::ios::app);
    if (!file.is_open())
        return;
    file << c;
    file.close();
}

/**
 * @brief Simulates the component starting from the subcomponents
 * @details If the component is not correctly set up, returns
 * @param currentName The name of the current component
*/
void Logger::subSimulate(std::string currentName)
{
    (void)currentName;

    _lastState = _currentState;
    _currentState = _pins[9]->getState();

    nts::Tristate inhibit = _pins[10]->getState();

    if (inhibit != nts::Tristate::False)
        return;

    if (_lastState == nts::Tristate::False && _currentState == nts::Tristate::True)
        writeChar(getCharFromPins());
}
