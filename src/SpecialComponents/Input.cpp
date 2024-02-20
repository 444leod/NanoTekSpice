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
            {1, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)}
        };
    _isInput = true;
}

Input::~Input()
{
}
