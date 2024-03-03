/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4069
*/

#include "My4069.hpp"
#include "../ElementatyComponents/Not.hpp"

/**
 * @brief My4069 class constructor
 * @details Implements the subcomponents of the 4069 component while also overriding the _pins
 * Has 14 pins: 6 inputs & 6 outputs, 2 ignored (VSS & VDD). Composed of 6 not gates
*/
My4069::My4069(std::string name) : AGatesComponent(name)
{
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_OUTPUT},
        {3, CREATE_INPUT},
        {4, CREATE_OUTPUT},
        {5, CREATE_INPUT},
        {6, CREATE_OUTPUT},
        {7, CREATE_IGNORED},
        {8, CREATE_OUTPUT},
        {9, CREATE_INPUT},
        {10, CREATE_OUTPUT},
        {11, CREATE_INPUT},
        {12, CREATE_OUTPUT},
        {13, CREATE_INPUT},
        {14, CREATE_IGNORED},
    };
     _subComponents = {
        {"Not1", std::make_shared<Not>("Not1")},
        {"Not2", std::make_shared<Not>("Not2")},
        {"Not3", std::make_shared<Not>("Not3")},
        {"Not4", std::make_shared<Not>("Not4")},
        {"Not5", std::make_shared<Not>("Not5")},
        {"Not6", std::make_shared<Not>("Not6")},
    };
}

/**
 * @brief Links the subcomponents of the 4069 component
*/
void My4069::linkSubComponents()
{
    _subComponents["Not1"]->getPin(1)->setLink(_pins[1]);
    _pins[2]->setLink(_subComponents["Not1"]->getPin(2));

    _subComponents["Not2"]->getPin(1)->setLink(_pins[3]);
    _pins[4]->setLink(_subComponents["Not2"]->getPin(2));

    _subComponents["Not3"]->getPin(1)->setLink(_pins[5]);
    _pins[6]->setLink(_subComponents["Not3"]->getPin(2));

    _subComponents["Not4"]->getPin(1)->setLink(_pins[9]);
    _pins[8]->setLink(_subComponents["Not4"]->getPin(2));

    _subComponents["Not5"]->getPin(1)->setLink(_pins[11]);
    _pins[10]->setLink(_subComponents["Not5"]->getPin(2));

    _subComponents["Not6"]->getPin(1)->setLink(_pins[13]);
    _pins[12]->setLink(_subComponents["Not6"]->getPin(2));
}

