/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** True
*/

#include "True.hpp"

using nts::components::True;

/**
 * @brief Create a True object
 * @details This class is used to create a True component with a given name
*/
True::True(std::string name) : ASpecialComponent(name)
{
    _pins = {
            {1, std::make_shared<nts::Pin>(this, nts::PinType::OUTPUT, nts::Tristate::True, true)}
        };
}
