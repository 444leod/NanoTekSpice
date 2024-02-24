/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4069
*/

#include "My4069.hpp"
#include "../ElementatyComponents/Not.hpp"

My4069::My4069(std::string name) : GatesComponent(name)
{
    _pins = {
        {1, NULL},
        {2, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},
        {3, NULL},
        {4, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},
        {5, NULL},
        {6, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},
        {7, NULL},
        {8, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},
        {9, NULL},
        {10, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},
        {11, NULL},
        {12, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},
        {13, NULL},
        {14, NULL}
    };
     _subComponents = {
        std::make_shared<Not>("Not1"),
        std::make_shared<Not>("Not2"),
        std::make_shared<Not>("Not3"),
        std::make_shared<Not>("Not4"),
        std::make_shared<Not>("Not5"),
        std::make_shared<Not>("Not6")
    };
}

My4069::~My4069()
{
}

void My4069::simulate()
{
    _subComponents[0]->forceSetLink(_pins[1], 1);
    _subComponents[0]->forceSetLink(_pins[2], 2);
    _subComponents[1]->forceSetLink(_pins[3], 1);
    _subComponents[1]->forceSetLink(_pins[4], 2);
    _subComponents[2]->forceSetLink(_pins[5], 1);
    _subComponents[2]->forceSetLink(_pins[6], 2);
    _subComponents[3]->forceSetLink(_pins[8], 1);
    _subComponents[3]->forceSetLink(_pins[9], 2);
    _subComponents[4]->forceSetLink(_pins[10], 1);
    _subComponents[4]->forceSetLink(_pins[11], 2);
    _subComponents[5]->forceSetLink(_pins[12], 1);
    _subComponents[5]->forceSetLink(_pins[13], 2);

    for (auto &subComponent : _subComponents) {
        subComponent->simulate();
    }
}

