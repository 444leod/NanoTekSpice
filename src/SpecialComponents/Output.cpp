/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(std::string name) : SpecialComponent(name)
{
    _pins = {
            {1, NULL}
        };
}

Output::~Output()
{
}
