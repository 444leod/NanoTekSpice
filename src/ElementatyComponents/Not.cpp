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
        {1, NULL},
        {2, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)}
    };
}

Not::~Not()
{
}

void Not::simulate()
{
    std::shared_ptr<nts::Pin> pin1 = getPin(1);
    if (pin1 == NULL || pin1->getState() == nts::Tristate::Undefined) {
        setPinValue(2, nts::Tristate::Undefined);
        return;
    }
    setPinValue(2, pin1->getState() == nts::Tristate::True ? nts::Tristate::False : nts::Tristate::True);
}
