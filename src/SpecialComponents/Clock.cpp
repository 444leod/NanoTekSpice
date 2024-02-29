/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(std::string name) : SpecialComponent(name)
{
    _pins = {
            {1, CREATE_OUTPUT}
        };
    _isInput = true;
}
