/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Clock
*/

#include "Clock.hpp"

/**
 * @brief Clock class
 * @details This class is used to create a clock component with a given name
*/
Clock::Clock(std::string name) : ASpecialComponent(name)
{
    _pins = {
            {1, CREATE_OUTPUT}
        };
    _isInput = true;
}
