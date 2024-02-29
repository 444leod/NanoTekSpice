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
        {"Or1", std::make_shared<Or>("Or1")},
        {"Or2", std::make_shared<Or>("Or2")},
        {"Or3", std::make_shared<Or>("Or3")},
        {"Or4", std::make_shared<Or>("Or4")},
    };
}

void My4071::linkSubComponents()
{
    _subComponents["Or1"]->getPin(1)->setLink(_pins[1]);
    _subComponents["Or1"]->getPin(2)->setLink(_pins[2]);
    _pins[3]->setLink(_subComponents["Or1"]->getPin(3));

    _pins[4]->setLink(_subComponents["Or2"]->getPin(3));
    _subComponents["Or2"]->getPin(1)->setLink(_pins[5]);
    _subComponents["Or2"]->getPin(2)->setLink(_pins[6]);

    _subComponents["Or3"]->getPin(1)->setLink(_pins[8]);
    _subComponents["Or3"]->getPin(2)->setLink(_pins[9]);
    _pins[10]->setLink(_subComponents["Or3"]->getPin(3));

    _pins[11]->setLink(_subComponents["Or4"]->getPin(3));
    _subComponents["Or4"]->getPin(1)->setLink(_pins[12]);
    _subComponents["Or4"]->getPin(2)->setLink(_pins[13]);
}
