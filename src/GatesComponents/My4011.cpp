/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4011
*/

#include "My4011.hpp"
#include "../ElementatyComponents/And.hpp"
#include "../ElementatyComponents/Not.hpp"

/**
 * @brief My4011 class constructor
 * @details Implements the subcomponents of the 4011 component
*/
My4011::My4011(std::string name) : AGatesComponent(name)
{
    _subComponents = {
        {"And1", std::make_shared<And>("And1")},
        {"And2", std::make_shared<And>("And2")},
        {"And3", std::make_shared<And>("And3")},
        {"And4", std::make_shared<And>("And4")},
        {"Not1", std::make_shared<Not>("Not1")},
        {"Not2", std::make_shared<Not>("Not2")},
        {"Not3", std::make_shared<Not>("Not3")},
        {"Not4", std::make_shared<Not>("Not4")}
    };
}

/**
 * @brief Links the subcomponents of the 4011 component
*/
void My4011::linkSubComponents()
{
    _subComponents["And1"]->setLink(3, _subComponents["Not1"], 1);
    _subComponents["And2"]->setLink(3, _subComponents["Not2"], 1);
    _subComponents["And3"]->setLink(3, _subComponents["Not3"], 1);
    _subComponents["And4"]->setLink(3, _subComponents["Not4"], 1);

    _subComponents["And1"]->getPin(1)->setLink(_pins[1]);
    _subComponents["And1"]->getPin(2)->setLink(_pins[2]);
    _pins[3]->setLink(_subComponents["Not1"]->getPin(2));
    _pins[4]->setLink(_subComponents["Not2"]->getPin(2));
    _subComponents["And2"]->getPin(2)->setLink(_pins[5]);
    _subComponents["And2"]->getPin(1)->setLink(_pins[6]);
    _subComponents["And3"]->getPin(1)->setLink(_pins[8]);
    _subComponents["And3"]->getPin(2)->setLink(_pins[9]);
    _pins[10]->setLink(_subComponents["Not3"]->getPin(2));
    _pins[11]->setLink(_subComponents["Not4"]->getPin(2));
    _subComponents["And4"]->getPin(1)->setLink(_pins[12]);
    _subComponents["And4"]->getPin(2)->setLink(_pins[13]);
}
