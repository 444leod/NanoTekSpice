/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ElementaryComponent
*/

#include "ElementaryComponent.hpp"

ElementaryComponent::ElementaryComponent(std::string name) : AComponent(name)
{
     _pins = {
            {1, NULL},
            {2, NULL},
            {3, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)}
        };
}

ElementaryComponent::~ElementaryComponent()
{
}
