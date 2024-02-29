/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Logger
*/

#pragma once

#include "../AComponent.hpp"

class Logger : public nts::AComponent {
    public:
        Logger(std::string name);
        ~Logger();
        void subSimulate(std::string currentName) override;

    protected:
    private:
        bool isInhibitFalse();
        char getCharFromBits(const std::array<int, 8>& bits);
        std::array<int, 8>getBitsFromPins();
        void writeChar(char c);
        nts::Tristate _lastState = nts::Tristate::Undefined;
        bool _isCorrectlySetUp = true;
};
