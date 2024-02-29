/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Not
*/

#include "Not.hpp"

Not::Not(std::string name) : ElementaryComponent(name)
{
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_OUTPUT}
    };
}

Not::~Not()
{
}

void Not::subSimulate(std::string currentName)
{
    (void)currentName;

    nts::Tristate output = _pins[1]->getState();

    if (output == nts::Tristate::True) {
        setPinValue(2, nts::Tristate::False);
    } else if (output == nts::Tristate::False) {
        setPinValue(2, nts::Tristate::True);
    } else {
        setPinValue(2, nts::Tristate::Undefined);
    }
}
