/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** SRLatch
*/

#include "SRLatch.hpp"
#include "Nor.hpp"

/**
 * @brief SRLatch class constructor
 * @details Has 2 input pins and 2 output pins
 * @details The SRLatch class is used to process a SRLatch gate
 * a SRLatch is a gated latch with two inputs, S and R, and two outputs, Q and Qnot
 * The S and R stand for Set and Reset, respectively
*/
SRLatch::SRLatch(std::string name) : ABonusComponent(name)
{
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_OUTPUT},
        {4, CREATE_OUTPUT}
    };

    _subComponents = {
        {"Nor1", std::make_shared<Nor>("Nor1")},
        {"Nor2", std::make_shared<Nor>("Nor2")}
    };
}

/**
 * @brief Link the subcomponents of the SRLatch
 * @details Link the subcomponents of the SRLatch
*/
void SRLatch::linkSubComponents()
{
    _subComponents["Nor1"]->getPin(1)->setLink(_pins[1]);
    _subComponents["Nor1"]->getPin(2)->setLink(_subComponents["Nor2"]->getPin(3));
    _subComponents["Nor2"]->getPin(1)->setLink(_subComponents["Nor1"]->getPin(3));
    _subComponents["Nor2"]->getPin(2)->setLink(_pins[2]);
    _pins[3]->setLink(_subComponents["Nor1"]->getPin(3));
    _pins[4]->setLink(_subComponents["Nor2"]->getPin(3));

    _subComponents["Nor1"]->linkSubComponents();
    _subComponents["Nor2"]->linkSubComponents();
}
