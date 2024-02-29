/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Logger
*/

#include "Logger.hpp"

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

char Logger::getCharFromBits(const std::array<int, 8>& bits) {
    char result = 0;
    for (int i = 0; i < 8; ++i) {
        result |= bits[i] << (7 - i);
    }
    return result;
}

std::array<int, 8> Logger::getBitsFromPins() {
    std::array<int, 8> bits = {0, 0, 0, 0, 0, 0, 0, 0};
    bool isEmptyChar = false;

    for (int i = 0; i < 8; i++) {
        if (!_pins[i + 1] || _pins[i + 1]->getState() == nts::Tristate::Undefined) {
            isEmptyChar = true;
            break;
        }
        bits[i] = _pins[i + 1]->getState() == nts::Tristate::True ? 1 : 0;
    }
    if (isEmptyChar)
        return {0, 0, 0, 0, 0, 0, 0, 0};
    return bits;
}

void Logger::writeChar(char c) {
    std::ofstream file;

    file.open("log.bin", std::ios::app);
    file << c;
}

bool Logger::isInhibitFalse() {
    if (!_pins[10]) {
        _isCorrectlySetUp = false;
        return false;
    }
    return _pins[10]->getState() == nts::Tristate::False;
}

void Logger::subSimulate(std::string currentName)
{
    (void)currentName;
    if (!_isCorrectlySetUp) return;
    if (!_pins[9] || !_pins[10]) {
        _isCorrectlySetUp = false;
        return;
    }
    if (_pins[10]->getState() != nts::Tristate::False) {
        _lastState = _pins[9]->getState();
        return;
    }

    if (_lastState != nts::Tristate::False || _pins[9]->getState() != nts::Tristate::True) {
        _lastState = _pins[9]->getState();
        return;
    }

    writeChar(getCharFromBits(getBitsFromPins()));

    _lastState = _pins[9]->getState();
}
