/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(std::string name) : ASpecialComponent(name)
{
    _pins = {
            {1, CREATE_INPUT},
        };
}
