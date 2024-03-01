/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4040
*/

#pragma once

#include "../AComponent.hpp"

/**
 * @brief My4040 class
 * @details The 4040 is a 12-bit counter
*/
class My4040 : public nts::AComponent {
    public:
        My4040(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
        void convertToPins();
        nts::Tristate _lastState = nts::Tristate::Undefined;
        nts::Tristate _currentState = nts::Tristate::Undefined;
        std::array<nts::Tristate, 12> _counter;
        std::uint16_t _value = 0;
};
