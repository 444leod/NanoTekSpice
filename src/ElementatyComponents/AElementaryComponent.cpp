/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AElementaryComponent
*/

#include "AElementaryComponent.hpp"

/**
 * @brief Constructor of AElementaryComponent
 * @details Used to initialize the pins of the component 
 * as most of the elementary components have the same pins
*/
AElementaryComponent::AElementaryComponent(std::string name) : AComponent(name)
{
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_OUTPUT}
    };
}
