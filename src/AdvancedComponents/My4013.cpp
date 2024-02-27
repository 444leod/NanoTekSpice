/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4013
*/

#include "My4013.hpp"

using nts::Tristate::False;
using nts::Tristate::True;
using nts::Tristate::Undefined;

My4013::My4013(std::string name) : AComponent(name)
{
    _pins = {
        {1, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, Undefined)},
        {2, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, Undefined)},
        {3, NULL},
        {4, NULL},
        {5, NULL},
        {6, NULL},
        {7, NULL},
        {8, NULL},
        {9, NULL},
        {10, NULL},
        {11, NULL},
        {12, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, Undefined)},
        {13, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, Undefined)},
    };
}

void My4013::simulate()
{
    _datas =    { _pins[5], _pins[9]  };
    _sets =     { _pins[6], _pins[8]  };
    _resets =   { _pins[4], _pins[10] };
    _clocks =   { _pins[3], _pins[11] };
    _qb =       { _pins[2], _pins[12] };
    _q =        { _pins[1], _pins[13] };

    std::vector<nts::Tristate> datas = {
        _datas[0] ? _datas[0]->getState() : Undefined,
        _datas[1] ? _datas[1]->getState() : Undefined
    };
    std::vector<nts::Tristate> sets = {
        _sets[0] ? _sets[0]->getState() : Undefined,
        _sets[1] ? _sets[1]->getState() : Undefined
    };
    std::vector<nts::Tristate> resets = {
        _resets[0] ? _resets[0]->getState() : Undefined,
        _resets[1] ? _resets[1]->getState() : Undefined
    };
    std::vector<nts::Tristate> clocks = {
        _clocks[0] ? _clocks[0]->getState() : Undefined,
        _clocks[1] ? _clocks[1]->getState() : Undefined
    };
    for (int i = 0; i < 2; i++) {
        if (sets[i] == True) {
            if (resets[i] == True) {
                _q[i]->setState(True);
                _qb[i]->setState(True);
            } else {
                _q[i]->setState(True);
                _qb[i]->setState(False);
            }
        } else if (resets[i] == True) {
            _q[i]->setState(False);
            _qb[i]->setState(True);
        } else if (clocks[i] == True && _lastState[i] == False) {
            if (datas[i] == True) {
                _q[i]->setState(True);
                _qb[i]->setState(False);
            } else if (datas[i] == False) {
                _q[i]->setState(False);
                _qb[i]->setState(True);
            }
        } else if (clocks[i] == False && _lastState[i] == True) {
        } else {
            _q[i]->setState(Undefined);
            _qb[i]->setState(Undefined);
        }
    }
    _lastState = {clocks[0], clocks[1]};
}
