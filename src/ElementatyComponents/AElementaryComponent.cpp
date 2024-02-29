/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AElementaryComponent
*/

#include "AElementaryComponent.hpp"

AElementaryComponent::AElementaryComponent(std::string name) : AComponent(name)
{
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_OUTPUT}
    };
}
