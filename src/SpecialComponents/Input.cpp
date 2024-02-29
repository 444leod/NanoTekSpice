/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(std::string name) : SpecialComponent(name)
{
    _pins = {
            {1, CREATE_OUTPUT}
        };
    _isInput = true;
}

Input::~Input()
{
}
