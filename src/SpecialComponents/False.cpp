/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** False
*/

#include "False.hpp"

using nts::components::False;

/**
 * @brief False class constructor
 * @details Defines the pin as an output pin
*/
False::False(std::string name) : ASpecialComponent(name)
{
    _pins = {
            {1, std::make_shared<nts::Pin>(this, nts::PinType::OUTPUT, nts::Tristate::False, true)}
        };
}
