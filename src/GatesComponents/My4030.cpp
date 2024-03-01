/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4030
*/

#include "My4030.hpp"
#include "../ElementatyComponents/Xor.hpp"

/**
 * @brief My4030 class constructor
 * @details Implements the subcomponents of the 4030 component
*/
My4030::My4030(std::string name) : AGatesComponent(name)
{
    _subComponents = {
        {"Xor1", std::make_shared<Xor>("Xor1")},
        {"Xor2", std::make_shared<Xor>("Xor2")},
        {"Xor3", std::make_shared<Xor>("Xor3")},
        {"Xor4", std::make_shared<Xor>("Xor4")},
    };
}

/**
 * @brief Links the subcomponents of the 4030 component
*/
void My4030::linkSubComponents()
{
    _subComponents["Xor1"]->getPin(1)->setLink(_pins[1]);
    _subComponents["Xor1"]->getPin(2)->setLink(_pins[2]);
    _pins[3]->setLink(_subComponents["Xor1"]->getPin(3));

    _pins[4]->setLink(_subComponents["Xor2"]->getPin(3));
    _subComponents["Xor2"]->getPin(1)->setLink(_pins[5]);
    _subComponents["Xor2"]->getPin(2)->setLink(_pins[6]);

    _subComponents["Xor3"]->getPin(1)->setLink(_pins[8]);
    _subComponents["Xor3"]->getPin(2)->setLink(_pins[9]);
    _pins[10]->setLink(_subComponents["Xor3"]->getPin(3));

    _pins[11]->setLink(_subComponents["Xor4"]->getPin(3));
    _subComponents["Xor4"]->getPin(1)->setLink(_pins[12]);
    _subComponents["Xor4"]->getPin(2)->setLink(_pins[13]);
}
