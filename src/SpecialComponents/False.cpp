/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** False
*/

#include "False.hpp"

using nts::components::False;

/**
 * @brief Create a False object
 * @details This class is used to create a False component with a given name
*/
False::False(std::string name) : ASpecialComponent(name)
{
    _pins = {
            {1, std::make_shared<nts::Pin>(this, nts::PinType::OUTPUT, nts::Tristate::False, true)}
        };
}
