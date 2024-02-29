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
        {1, CREATE_INPUT},//x0
        {2, CREATE_INPUT},//x1
        {3, CREATE_INPUT},//x2
        {4, CREATE_INPUT},//x3
        {5, CREATE_INPUT},//x4
        {6, CREATE_INPUT},//x5
        {7, CREATE_INPUT},//x6
        {8, CREATE_IGNORED},//VSS
        {9, CREATE_INPUT},//x7
        {10, CREATE_INPUT},//inhibit
        {11, CREATE_INPUT},//adress input A
        {12, CREATE_INPUT},//adress input B
        {13, CREATE_INPUT},//adress input C
        {14, CREATE_OUTPUT},//Z
        {15, CREATE_INPUT},//OE
        {16, CREATE_IGNORED}//VDD
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

void My4512::subSimulate(std::string currentName)
{
    (void)currentName;
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
