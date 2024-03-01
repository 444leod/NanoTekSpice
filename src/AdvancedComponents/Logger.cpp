/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Logger
*/

#include "Logger.hpp"
#include <cmath>

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

bool Logger::isInhibitFalse() {
    return _pins[10]->getState() == nts::Tristate::False;
}

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
