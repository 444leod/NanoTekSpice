/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4030
*/

#include "My4030.hpp"
#include "../ElementatyComponents/Xor.hpp"


My4030::My4030(std::string name) : GatesComponent(name)
{
    _subComponents = {
        std::make_shared<Xor>("Xor1"),
        std::make_shared<Xor>("Xor2"),
        std::make_shared<Xor>("Xor3"),
        std::make_shared<Xor>("Xor4"),
    };
}

My4030::~My4030()
{
}

void My4030::simulate()
{
    _subComponents[0]->forceSetLink(_pins[1], 1);
    _subComponents[0]->forceSetLink(_pins[2], 2);
    _subComponents[0]->forceSetLink(_pins[3], 3);
    _subComponents[1]->forceSetLink(_pins[5], 1);
    _subComponents[1]->forceSetLink(_pins[6], 2);
    _subComponents[1]->forceSetLink(_pins[4], 3);
    _subComponents[2]->forceSetLink(_pins[8], 1);
    _subComponents[2]->forceSetLink(_pins[9], 2);
    _subComponents[2]->forceSetLink(_pins[10], 3);
    _subComponents[3]->forceSetLink(_pins[12], 1);
    _subComponents[3]->forceSetLink(_pins[13], 2);
    _subComponents[3]->forceSetLink(_pins[11], 3);

    for (auto &subComponent : _subComponents) {
        subComponent->simulate();
    }
}
