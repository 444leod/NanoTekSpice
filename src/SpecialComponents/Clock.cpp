/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Clock
*/

#include "Clock.hpp"

/**
 * @brief Clock class constructor
 * @details Defines the pin as an output pin
*/
Clock::Clock(std::string name) : ASpecialComponent(name)
{
    _pins = {
            {1, CREATE_OUTPUT}
        };
    _isInput = true;
}
