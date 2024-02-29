/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4017
*/

#pragma once

#include "../AComponent.hpp"

class My4017 : public nts::AComponent {
    public:
        My4017(std::string name);
        ~My4017() = default;
        void subSimulate(std::string currentName) override;

    protected:
    private:
        std::vector<nts::Tristate> _lastStates = { nts::Tristate::Undefined, nts::Tristate::Undefined};
        std::vector<nts::Tristate> _currentStates = { nts::Tristate::Undefined, nts::Tristate::Undefined};
        std::vector<std::shared_ptr<nts::Pin>> _outputs;
        size_t _currentOutput = 0;
        void handleReset();
        std::vector<std::shared_ptr<nts::IComponent>> _subcomponents;
        std::map<int, int> _outputPins = {
            {0, 3},
            {1, 2},
            {2, 4},
            {3, 7},
            {4, 10},
            {5, 1},
            {6, 5},
            {7, 6},
            {8, 9},
            {9, 11}
        };
};
