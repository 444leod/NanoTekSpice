/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4081
*/

#include "My4081.hpp"
#include "../ElementatyComponents/And.hpp"

My4081::My4081(std::string name) : AGatesComponent(name)
{
    _subComponents = {
        {"And1", std::make_shared<And>("And1")},
        {"And2", std::make_shared<And>("And2")},
        {"And3", std::make_shared<And>("And3")},
        {"And4", std::make_shared<And>("And4")},
    };
}

void My4081::linkSubComponents()
{
    _subComponents["And1"]->getPin(1)->setLink(_pins[1]);
    _subComponents["And1"]->getPin(2)->setLink(_pins[2]);
    _pins[3]->setLink(_subComponents["And1"]->getPin(3));

    _pins[4]->setLink(_subComponents["And2"]->getPin(3));
    _subComponents["And2"]->getPin(1)->setLink(_pins[5]);
    _subComponents["And2"]->getPin(2)->setLink(_pins[6]);

    _subComponents["And3"]->getPin(1)->setLink(_pins[8]);
    _subComponents["And3"]->getPin(2)->setLink(_pins[9]);
    _pins[10]->setLink(_subComponents["And3"]->getPin(3));

    _pins[11]->setLink(_subComponents["And4"]->getPin(3));
    _subComponents["And4"]->getPin(1)->setLink(_pins[12]);
    _subComponents["And4"]->getPin(2)->setLink(_pins[13]);
}
