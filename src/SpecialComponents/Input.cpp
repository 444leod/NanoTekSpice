/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Input
*/

#include "Input.hpp"

/**
 * @brief Input class constructor
 * @details Defines the pin as an output pin
*/
Input::Input(std::string name) : ASpecialComponent(name)
{
    _pins = {
            {1, CREATE_OUTPUT}
        };
    _isInput = true;
}
