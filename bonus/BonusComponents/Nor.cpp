/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Nor
*/

#include "Nor.hpp"
#include "../ElementatyComponents/Or.hpp"
#include "../ElementatyComponents/Not.hpp"

/**
 * @brief Nor class
 * @details The Nor class is used to process a nor gate
 * a nor gate is a gate with two inputs and one output
 * the output is true if both inputs are false
 * the output is false if at least one input is true
 * the nor gate is the opposite of the or gate
*/
Nor::Nor(std::string name) : ABonusComponent(name)
{
    _subComponents = {
        {"A", std::make_shared<Or>("A")},
        {"B", std::make_shared<Not>("B")}
    };
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_OUTPUT}
    };
}

/**
 * @brief Link the subcomponents of the Nor
 * @details Link the subcomponents of the Nor
*/
void Nor::linkSubComponents()
{
    _subComponents["A"]->getPin(1)->setLink(_pins[1]);
    _subComponents["A"]->getPin(2)->setLink(_pins[2]);
    _subComponents["B"]->getPin(1)->setLink(_subComponents["A"]->getPin(3));
    _pins[3]->setLink(_subComponents["B"]->getPin(2));
}
