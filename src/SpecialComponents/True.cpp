/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** True
*/

#include "True.hpp"

using nts::components::True;

/**
 * @brief True class constructor
 * @details Defines the pin as an output pin
*/
True::True(std::string name) : ASpecialComponent(name)
{
    _pins = {
            {1, std::make_shared<nts::Pin>(this, nts::PinType::OUTPUT, nts::Tristate::True, true)}
        };
}
