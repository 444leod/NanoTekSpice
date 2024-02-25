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
        {1, NULL},
        {2, NULL},
        {3, NULL},
        {4, NULL},
        {5, NULL},
        {6, NULL},
        {7, NULL},
        {8, NULL},
        {9, NULL},
        {10, NULL}
    };
}

Logger::~Logger()
{
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

    file.open("log.txt", std::ios::app);
    file << c;
}

bool Logger::isInhibitFalse() {
    if (!_pins[10]) {
        _isCorrectlySetUp = false;
        return false;
    }
    return _pins[10]->getState() == nts::Tristate::False;
}

void Logger::simulate()
{
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
