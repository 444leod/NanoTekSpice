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
        {1, NULL},
        {2, NULL},
        {3, NULL},
        {4, NULL},
        {5, NULL},
        {6, NULL},
        {7, NULL},
        {8, std::make_shared<nts::Pin>(this, nts::PinType::INPUT, nts::Tristate::Undefined, false, true)},
        {9, NULL},
        {10, CREATE_OUTPUT},
        {11, CREATE_OUTPUT},
        {12, CREATE_OUTPUT},
        {13, CREATE_OUTPUT},
        {14, CREATE_OUTPUT},
        {15, NULL},
        {16, std::make_shared<nts::Pin>(this, nts::PinType::INPUT, nts::Tristate::Undefined, false, true)}
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
