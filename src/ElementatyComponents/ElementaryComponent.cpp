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
            {1, CREATE_INPUT},
            {2, CREATE_INPUT},
            {3, CREATE_OUTPUT}
        };
}

ElementaryComponent::~ElementaryComponent()
{
}
