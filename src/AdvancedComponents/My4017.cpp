/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4017
*/

#include "My4017.hpp"

using nts::Tristate::True;
using nts::Tristate::False;
using nts::Tristate::Undefined;
using nts::PinType::OUTPUT;
using nts::PinType::INPUT;

My4017::My4017(std::string name) : AComponent(name)
{
    _pins = {
        {1, std::make_shared<nts::Pin>(this, OUTPUT, False)},
        {2, std::make_shared<nts::Pin>(this, OUTPUT, False)},
        {3, std::make_shared<nts::Pin>(this, OUTPUT, True)},
        {4, std::make_shared<nts::Pin>(this, OUTPUT, False)},
        {5, std::make_shared<nts::Pin>(this, OUTPUT, False)},
        {6, std::make_shared<nts::Pin>(this, OUTPUT, False)},
        {7, std::make_shared<nts::Pin>(this, OUTPUT, False)},
        {8, std::make_shared<nts::Pin>(this, OUTPUT, False)},
        {9, std::make_shared<nts::Pin>(this, OUTPUT, False)},
        {10, std::make_shared<nts::Pin>(this, OUTPUT, False)},
        {11, std::make_shared<nts::Pin>(this, OUTPUT, False)},
        {12, std::make_shared<nts::Pin>(this, OUTPUT, True)},
        {13, NULL},
        {14, NULL},
        {15, NULL},
    };
}

void My4017::subSimulate(std::string currentName)
{
    (void)currentName;

    _lastStates = _currentStates;
    nts::Tristate cp0 = _pins[13] ? _pins[13]->getState() : Undefined;
    nts::Tristate cp1 = _pins[14] ? _pins[14]->getState() : Undefined;
    nts::Tristate reset = _pins[15] ? _pins[15]->getState() : Undefined;

    if (cp1 == True)
        cp1 = False;
    else if (cp1 == False)
        cp1 = True;
    _currentStates = {cp0, cp1};

    if (reset == True) {
        handleReset();
        return;
    }
    if ((cp0 == True && _lastStates[0] == False && cp1 == False)
        || (cp1 == True && _lastStates[1] == False && cp0 == True)) {
        _currentOutput++;
        if (_currentOutput > 9)
            _currentOutput = 0;
    }
    for (int i = 1; i <= 11; i++) {
        _pins[i]->setState(False);
    }
    _pins[_outputPins[_currentOutput]]->setState(True);
    _pins[12]->setState(_currentOutput >= 5 ? False : True);
}

void My4017::handleReset()
{
    _currentOutput = 0;
    for (int i = 1; i <= 11; i++) {
        _pins[i]->setState(False);
    }
    _pins[3]->setState(True);
    _pins[12]->setState(True);
}
