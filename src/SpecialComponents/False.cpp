/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** False
*/

#include "False.hpp"

using nts::components::False;

False::False(std::string name) : SpecialComponent(name)
{
    _pins = {
            {1, std::make_shared<nts::Pin>(this, nts::PinType::OUTPUT, nts::Tristate::False, true)}
        };
}

False::~False()
{
}
