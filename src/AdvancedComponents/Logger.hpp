/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Logger
*/

#pragma once

#include "../AComponent.hpp"

/**
 * @brief Logger class
 * @details The Logger class is used to log the output of a circuit to a file
*/
class Logger : public nts::AComponent {
    public:
        Logger(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
        char getCharFromPins();
        void writeChar(char c);
        nts::Tristate _lastState = nts::Tristate::Undefined;
        nts::Tristate _currentState = nts::Tristate::Undefined;
};
