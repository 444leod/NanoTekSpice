/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** GatedSRLatch
*/

#include "GatedSRLatch.hpp"
#include "../ElementatyComponents/Not.hpp"
#include "../ElementatyComponents/And.hpp"
#include "SRLatch.hpp"

/**
 * @brief GatedSRLatch class constructor
 * @details Has 3 input pins and 2 output pins
 * @details The GatedSRLatch class is used to process a GatedSRLatch gate
 * a GatedSRLatch is a gated latch with 3 inputs, S, R and E, and 2 outputs, Q and Qnot
 * The S and R stand for Set and Reset, respectively
 * The E stands for Enable
*/
GatedSRLatch::GatedSRLatch(std::string name) : ABonusComponent(name)
{
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_INPUT},
        {4, CREATE_OUTPUT},
        {5, CREATE_OUTPUT}
    };

    _subComponents = {
        {"And1", std::make_shared<And>("And1")},
        {"And2", std::make_shared<And>("And2")},
        {"Latch", std::make_shared<SRLatch>("Latch")}
    };
}

/**
 * @brief Link the subcomponents of the GatedSRLatch
 * @details Link the subcomponents of the GatedSRLatch
*/
void GatedSRLatch::linkSubComponents()
{
    _subComponents["Not"]->getPin(1)->setLink(_pins[1]);
    _subComponents["And2"]->getPin(2)->setLink(_pins[1]);
    _subComponents["And2"]->getPin(1)->setLink(_pins[2]);
    _subComponents["And1"]->getPin(1)->setLink(_pins[1]);
    _subComponents["And1"]->getPin(2)->setLink(_pins[2]);
    _subComponents["Latch"]->getPin(1)->setLink(_subComponents["And1"]->getPin(3));
    _subComponents["Latch"]->getPin(2)->setLink(_subComponents["And2"]->getPin(3));
    _pins[4]->setLink(_subComponents["Latch"]->getPin(3));
    _pins[5]->setLink(_subComponents["Latch"]->getPin(4));

    _subComponents["Latch"]->linkSubComponents();
}
