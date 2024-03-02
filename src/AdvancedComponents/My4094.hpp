/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4094
*/

#pragma once

#include "../AComponent.hpp"

class My4094 : public nts::AComponent {
    public:
        My4094(std::string name);
        void subSimulate(std::string currentName) override;
        void linkSubComponents();

    protected:
    private:
        void lowToHigh(nts::Tristate strobe, nts::Tristate data, nts::Tristate enable);
        void highToLow(nts::Tristate strobe, nts::Tristate data, nts::Tristate enable);
        std::vector<std::shared_ptr<nts::Pin>> _qPins;
        nts::Tristate _lastState = nts::Tristate::Undefined;
        nts::Tristate _actualState = nts::Tristate::Undefined;
};
