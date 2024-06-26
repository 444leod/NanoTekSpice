/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4008
*/

#include "My4008.hpp"

/**
 * @brief My4008 class constructor
 * @details Has 16 pins: 8 inputs, 4 outputs, 1 carry in and 1 carry out
*/
My4008::My4008(std::string name) : AComponent(name)
{
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_INPUT},
        {4, CREATE_INPUT},
        {5, CREATE_INPUT},
        {6, CREATE_INPUT},
        {7, CREATE_INPUT},
        {8, CREATE_IGNORED},
        {9, CREATE_INPUT},
        {10, CREATE_OUTPUT},
        {11, CREATE_OUTPUT},
        {12, CREATE_OUTPUT},
        {13, CREATE_OUTPUT},
        {14, CREATE_OUTPUT},
        {15, CREATE_INPUT},
        {16, CREATE_IGNORED}
    };
}

/**
 * @brief Simulates the component starting from the subcomponents
 * @param currentName The name of the current component
*/
void My4008::subSimulate(std::string currentName)
{
    (void)currentName;
    std::vector<std::pair<std::shared_ptr<nts::Pin>, std::shared_ptr<nts::Pin>>> pais = {
        {_pins[7], _pins[6]},
        {_pins[5], _pins[4]},
        {_pins[3], _pins[2]},
        {_pins[1], _pins[15]}
    };
    std::vector<std::shared_ptr<nts::Pin>> outputs = {
        _pins[10],
        _pins[11],
        _pins[12],
        _pins[13],
    };
    nts::Tristate carry = _pins[9] ? _pins[9]->getState() : nts::Tristate::Undefined;
    std::shared_ptr<nts::Pin> carryOutput = _pins[14];

    int i = -1;
    nts::Tristate a;
    nts::Tristate b;
    std::shared_ptr<nts::Pin> sum;
    for (auto &pair : pais) {
        i++;
        a = pair.first ? pair.first->getState() : nts::Tristate::Undefined;
        b = pair.second ? pair.second->getState() : nts::Tristate::Undefined;
        sum = outputs[i];
        if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined || carry == nts::Tristate::Undefined) {
            outputs[i]->setState(nts::Tristate::Undefined);
            carry = nts::Tristate::Undefined;
            continue;
        }
        sum->setState(static_cast<nts::Tristate>(a ^ b ^ carry));
        carry = static_cast<nts::Tristate>((a & b) | (a & carry) | (b & carry));
    }
    carryOutput->setState(carry);
}
