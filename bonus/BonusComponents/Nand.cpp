/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Nand
*/

#include "Nand.hpp"
#include "../ElementatyComponents/And.hpp"
#include "../ElementatyComponents/Not.hpp"

/**
 * @brief Nand class constructor
 * @details Has 2 input pins and 1 output pin
 * @details The Nand class is used to process a Nand gate
 * a Nand is a gate with 2 inputs and 1 output
 * the output is true if both inputs are false
 * the output is false if at least one input is true
 * the nand gate is the opposite of the and gate
*/
Nand::Nand(std::string name) : ABonusComponent(name)
{
    _subComponents = {
        {"A", std::make_shared<And>("A")},
        {"B", std::make_shared<Not>("B")}
    };
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_OUTPUT}
    };
}

/**
 * @brief Link the subcomponents of the Nand
 * @details Link the subcomponents of the Nand
*/
void Nand::linkSubComponents()
{
    _subComponents["A"]->getPin(1)->setLink(_pins[1]);
    _subComponents["A"]->getPin(2)->setLink(_pins[2]);
    _subComponents["B"]->getPin(1)->setLink(_subComponents["A"]->getPin(3));
    _pins[3]->setLink(_subComponents["B"]->getPin(2));
}
