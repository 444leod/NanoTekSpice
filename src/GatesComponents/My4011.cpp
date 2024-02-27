/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4011
*/

#include "My4011.hpp"
#include "../ElementatyComponents/And.hpp"
#include "../ElementatyComponents/Not.hpp"

My4011::My4011(std::string name) : GatesComponent(name)
{
    _subComponents = {
        std::make_shared<And>("And1"),
        std::make_shared<And>("And2"),
        std::make_shared<And>("And3"),
        std::make_shared<And>("And4"),
        std::make_shared<Not>("Not1"),
        std::make_shared<Not>("Not2"),
        std::make_shared<Not>("Not3"),
        std::make_shared<Not>("Not4")
    };
}

My4011::~My4011()
{
}

void My4011::simulate()
{
    _subComponents[4]->forceSetLink(_pins[3], 2);
    _subComponents[5]->forceSetLink(_pins[4], 2);
    _subComponents[6]->forceSetLink(_pins[10], 2);
    _subComponents[7]->forceSetLink(_pins[11], 2);

    _subComponents[0]->forceSetLink(_pins[1], 1);
    _subComponents[0]->forceSetLink(_pins[2], 2);
    _subComponents[4]->forceSetLink(_subComponents[0]->getPin(3), 1);
    _subComponents[1]->forceSetLink(_pins[5], 1);
    _subComponents[1]->forceSetLink(_pins[6], 2);
    _subComponents[5]->forceSetLink(_subComponents[1]->getPin(3), 1);
    _subComponents[2]->forceSetLink(_pins[8], 1);
    _subComponents[2]->forceSetLink(_pins[9], 2);
    _subComponents[6]->forceSetLink(_subComponents[2]->getPin(3), 1);
    _subComponents[3]->forceSetLink(_pins[12], 1);
    _subComponents[3]->forceSetLink(_pins[13], 2);
    _subComponents[7]->forceSetLink(_subComponents[3]->getPin(3), 1);

    for (auto &subComponent : _subComponents)
        subComponent->simulate();
}
