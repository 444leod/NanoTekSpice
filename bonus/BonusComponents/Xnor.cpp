/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Xnor
*/

#include "Xnor.hpp"
#include "../ElementatyComponents/Xor.hpp"
#include "../ElementatyComponents/Not.hpp"

Xnor::Xnor(std::string name) : ABonusComponent(name)
{
    _subComponents = {
        {"A", std::make_shared<Xor>("A")},
        {"B", std::make_shared<Not>("B")}
    };
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_OUTPUT}
    };
}

void Xnor::linkSubComponents()
{
    _subComponents["A"]->getPin(1)->setLink(_pins[1]);
    _subComponents["A"]->getPin(2)->setLink(_pins[2]);
    _subComponents["B"]->getPin(1)->setLink(_subComponents["A"]->getPin(3));
    _pins[3]->setLink(_subComponents["B"]->getPin(2));
}
