/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4512
*/

#include "My4512.hpp"

My4512::My4512(std::string name) : AComponent(name)
{
    _pins = {
        {1, NULL},//x0
        {2, NULL},//x1
        {3, NULL},//x2
        {4, NULL},//x3
        {5, NULL},//x4
        {6, NULL},//x5
        {7, NULL},//x6
        {8, std::make_shared<nts::Pin>(nts::PinType::INPUT, nts::Tristate::Undefined, false, true)},//VSS
        {9, NULL},//x7
        {10, NULL},//inhibit
        {11, NULL},//adress input A
        {12, NULL},//adress input B
        {13, NULL},//adress input C
        {14, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},//Z
        {15, NULL},//OE
        {16, std::make_shared<nts::Pin>(nts::PinType::INPUT, nts::Tristate::Undefined, false, true)}//VDD
    };
}

void My4512::adrressInputs()
{
    nts::Tristate a = !_pins[11] ? nts::Tristate::Undefined : _pins[11]->getState();
    nts::Tristate b = !_pins[12] ? nts::Tristate::Undefined : _pins[12]->getState();
    nts::Tristate c = !_pins[13] ? nts::Tristate::Undefined : _pins[13]->getState();

    if (c == nts::Tristate::Undefined || b == nts::Tristate::Undefined || a == nts::Tristate::Undefined)
        return;

    if (c == nts::Tristate::False && b == nts::Tristate::False && a == nts::Tristate::False) {
        _pins[14]->setState(_pins[1]->getState());
        return;
    }
    if (c == nts::Tristate::False && b == nts::Tristate::False && a == nts::Tristate::True) {
        _pins[14]->setState(_pins[2]->getState());
        return;
    }
    if (c == nts::Tristate::False && b == nts::Tristate::True && a == nts::Tristate::False) {
        _pins[14]->setState(_pins[3]->getState());
        return;
    }
    if (c == nts::Tristate::False && b == nts::Tristate::True && a == nts::Tristate::True) {
        _pins[14]->setState(_pins[4]->getState());
        return;
    }
    if (c == nts::Tristate::True && b == nts::Tristate::False && a == nts::Tristate::False) {
        _pins[14]->setState(_pins[5]->getState());
        return;
    }
    if (c == nts::Tristate::True && b == nts::Tristate::False && a == nts::Tristate::True) {
        _pins[14]->setState(_pins[6]->getState());
        return;
    }
    if (c == nts::Tristate::True && b == nts::Tristate::True && a == nts::Tristate::False) {
        _pins[14]->setState(_pins[7]->getState());
        return;
    }
    if (c == nts::Tristate::True && b == nts::Tristate::True && a == nts::Tristate::True) {
        _pins[14]->setState(_pins[9]->getState());
        return;
    }    
}

void My4512::simulate()
{
    if (!_pins[10] || !_pins[15])
        return;
    if (_pins[15]->getState() == nts::Tristate::True) {
        _pins[14]->setState(nts::Tristate::Undefined);
        return;
    }
    if (_pins[10]->getState() == nts::Tristate::True) {
        _pins[14]->setState(nts::Tristate::False);
        return;
    }
    if (!_pins[11] || !_pins[12] || !_pins[13])
        return;
    adrressInputs();
}
