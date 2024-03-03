/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** DFlipFlop
*/

#include "DFlipFlop.hpp"
#include "Nor.hpp"
#include "../ElementatyComponents/And.hpp"
#include "../ElementatyComponents/Not.hpp"


/**
 * @brief DFlipFlop class constructor
 * @details Has 2 input pins and 2 output pins
 * @details The DFlipFlop class is used to process a DFlipFlop gate
 * a DFlipFlop is a gated latch with 2 inputs, D and E, and 2 outputs, Q and Qnot
 * The D stands for Data and E stands for Enable
*/
DFlipFlop::DFlipFlop(std::string name) : ABonusComponent(name)
{
    _pins = {
        {1, CREATE_INPUT}, // Set
        {2, CREATE_INPUT}, // Data
        {3, CREATE_INPUT}, // Clock
        {4, CREATE_INPUT}, // Reset
        {5, CREATE_OUTPUT}, // Q
        {6, CREATE_OUTPUT} // Qnot
    };

    _subComponents = {
        {"And1", std::make_shared<TriInputElementary<And>>("And1")},
        {"And2", std::make_shared<TriInputElementary<And>>("And2")},
        {"And3", std::make_shared<TriInputElementary<And>>("And3")},
        {"And4", std::make_shared<TriInputElementary<And>>("And4")},
        {"And5", std::make_shared<TriInputElementary<And>>("And5")},
        {"And6", std::make_shared<TriInputElementary<And>>("And6")},
        {"Not1", std::make_shared<Not>("Not1")},
        {"Not2", std::make_shared<Not>("Not2")},
        {"Not3", std::make_shared<Not>("Not3")},
        {"Not4", std::make_shared<Not>("Not4")},
        {"Not5", std::make_shared<Not>("Not5")},
        {"Not6", std::make_shared<Not>("Not6")}
    };
}
/**
 * @brief Link the subcomponents of the DFlipFlop
 * @details Link the subcomponents of the DFlipFlop
*/
void DFlipFlop::linkSubComponents()
{
    std::shared_ptr<nts::Pin> Set = _pins[1];
    std::shared_ptr<nts::Pin> Clock = _pins[2];
    std::shared_ptr<nts::Pin> Data = _pins[3];
    std::shared_ptr<nts::Pin> Reset = _pins[4];

    _subComponents["Not1"]->getPin(1)->setLink(_subComponents["And1"]->getPin(4));
    _subComponents["Not2"]->getPin(1)->setLink(_subComponents["And2"]->getPin(4));
    _subComponents["Not3"]->getPin(1)->setLink(_subComponents["And3"]->getPin(4));
    _subComponents["Not4"]->getPin(1)->setLink(_subComponents["And4"]->getPin(4));
    _subComponents["Not5"]->getPin(1)->setLink(_subComponents["And5"]->getPin(4));
    _subComponents["Not6"]->getPin(1)->setLink(_subComponents["And6"]->getPin(4));

    _subComponents["And1"]->getPin(1)->setLink(Set);
    _subComponents["And1"]->getPin(2)->setLink(_subComponents["Not4"]->getPin(2));
    _subComponents["And1"]->getPin(3)->setLink(_subComponents["Not2"]->getPin(2));

    _subComponents["And2"]->getPin(1)->setLink(_subComponents["Not1"]->getPin(2));
    _subComponents["And2"]->getPin(2)->setLink(Clock);
    _subComponents["And2"]->getPin(3)->setLink(Reset);

    _subComponents["And3"]->getPin(1)->setLink(_subComponents["Not2"]->getPin(2));
    _subComponents["And3"]->getPin(2)->setLink(Clock);
    _subComponents["And3"]->getPin(3)->setLink(_subComponents["Not4"]->getPin(2));

    _subComponents["And4"]->getPin(1)->setLink(_subComponents["Not3"]->getPin(2));
    _subComponents["And4"]->getPin(2)->setLink(Data);
    _subComponents["And4"]->getPin(3)->setLink(Reset);

    _subComponents["And5"]->getPin(1)->setLink(Set);
    _subComponents["And5"]->getPin(2)->setLink(_subComponents["Not2"]->getPin(2));
    _subComponents["And5"]->getPin(3)->setLink(_subComponents["Not6"]->getPin(2));

    _subComponents["And6"]->getPin(1)->setLink(_subComponents["Not5"]->getPin(2));
    _subComponents["And6"]->getPin(2)->setLink(_subComponents["Not3"]->getPin(2));
    _subComponents["And6"]->getPin(3)->setLink(Reset);

    _pins[5]->setLink(_subComponents["Not5"]->getPin(2));
    _pins[6]->setLink(_subComponents["Not6"]->getPin(2));

    for (auto &subComponent : _subComponents) {
        subComponent.second->linkSubComponents();
    }


}
