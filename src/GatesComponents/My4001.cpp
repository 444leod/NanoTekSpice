/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4001
*/

#include "My4001.hpp"
#include "../ElementatyComponents/Or.hpp"
#include "../ElementatyComponents/Not.hpp"


My4001::My4001(std::string name) : GatesComponent(name)
{
    _subComponents = {
        {"Or1", std::make_shared<Or>("Or1")},
        {"Or2", std::make_shared<Or>("Or2")},
        {"Or3", std::make_shared<Or>("Or3")},
        {"Or4", std::make_shared<Or>("Or4")},
        {"Not1", std::make_shared<Not>("Not1")},
        {"Not2", std::make_shared<Not>("Not2")},
        {"Not3", std::make_shared<Not>("Not3")},
        {"Not4", std::make_shared<Not>("Not4")}
    };
}

void My4001::linkSubComponents()
{
    _subComponents["Or1"]->setLink(3, _subComponents["Not1"], 1);
    _subComponents["Or2"]->setLink(3, _subComponents["Not2"], 1);
    _subComponents["Or3"]->setLink(3, _subComponents["Not3"], 1);
    _subComponents["Or4"]->setLink(3, _subComponents["Not4"], 1);

    _subComponents["Or1"]->getPin(1)->setLink(_pins[1]);
    _subComponents["Or1"]->getPin(2)->setLink(_pins[2]);
    _pins[3]->setLink(_subComponents["Not1"]->getPin(2));
    _pins[4]->setLink(_subComponents["Not2"]->getPin(2));
    _subComponents["Or2"]->getPin(2)->setLink(_pins[5]);
    _subComponents["Or2"]->getPin(1)->setLink(_pins[6]);
    _subComponents["Or3"]->getPin(1)->setLink(_pins[8]);
    _subComponents["Or3"]->getPin(2)->setLink(_pins[9]);
    _pins[10]->setLink(_subComponents["Not3"]->getPin(2));
    _pins[11]->setLink(_subComponents["Not4"]->getPin(2));
    _subComponents["Or4"]->getPin(1)->setLink(_pins[12]);
    _subComponents["Or4"]->getPin(2)->setLink(_pins[13]);
}
