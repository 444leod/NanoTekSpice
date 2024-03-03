/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** GatedDLatch
*/

#include "GatedDLatch.hpp"
#include "../ElementatyComponents/Not.hpp"
#include "../ElementatyComponents/And.hpp"
#include "SRLatch.hpp"

/**
 * @brief GatedDLatch class constructor
 * @details Has 2 input pins and 2 output pins
 * @details The GatedDLatch class is used to process a GatedDLatch gate
 * a GatedDLatch is a gated latch with 2 inputs, D and E, and 2 outputs, Q and Qnot
 * The D stands for Data and E stands for Enable
*/
GatedDLatch::GatedDLatch(std::string name) : ABonusComponent(name)
{
    _pins = {
        {1, CREATE_INPUT}, // D
        {2, CREATE_INPUT}, // E
        {3, CREATE_OUTPUT}, // Q
        {4, CREATE_OUTPUT} // Qnot
    };

    _subComponents = {
        {"Not", std::make_shared<Not>("Not")},
        {"And1", std::make_shared<And>("And1")},
        {"And2", std::make_shared<And>("And2")},
        {"Latch", std::make_shared<SRLatch>("Latch")}
    };
}
/**
 * @brief Link the subcomponents of the GatedDLatch
 * @details Link the subcomponents of the GatedDLatch
*/
void GatedDLatch::linkSubComponents()
{
    _subComponents["Not"]->getPin(1)->setLink(_pins[1]);
    _subComponents["And2"]->getPin(2)->setLink(_pins[1]);
    _subComponents["And2"]->getPin(1)->setLink(_pins[2]);
    _subComponents["And1"]->getPin(1)->setLink(_subComponents["Not"]->getPin(2));
    _subComponents["And1"]->getPin(2)->setLink(_pins[2]);
    _subComponents["Latch"]->getPin(1)->setLink(_subComponents["And1"]->getPin(3));
    _subComponents["Latch"]->getPin(2)->setLink(_subComponents["And2"]->getPin(3));

    _subComponents["Latch"]->linkSubComponents();
}
