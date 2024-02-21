/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4071
*/

#include "My4071.hpp"
#include "../ElementatyComponents/Or.hpp"

My4071::My4071(std::string name) : GatesComponent(name)
{
    _subComponents = {
        std::make_shared<Or>("Or1"),
        std::make_shared<Or>("Or2"),
        std::make_shared<Or>("Or3"),
        std::make_shared<Or>("Or4"),
    };
}

My4071::~My4071()
{
}

void My4071::simulate()
{
    _subComponents[4]->forceSetLink(_pins[3], 2);
    _subComponents[5]->forceSetLink(_pins[4], 2);
    _subComponents[6]->forceSetLink(_pins[10], 2);
    _subComponents[7]->forceSetLink(_pins[11], 2);

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
