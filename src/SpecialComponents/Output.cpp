/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Output
*/

#include "Output.hpp"

/**
 * @brief Output class constructor
 * @details Defines the pin as an output pin
*/
Output::Output(std::string name) : ASpecialComponent(name)
{
    _pins = {
            {1, CREATE_INPUT},
        };
}
