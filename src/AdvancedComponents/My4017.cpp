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

/**
 * @brief My4017 class constructor
 * @details Has 15 pins: 10 output pins, 3 input pins (2 clock pins),
 * 1 output from the most significant flip-flop, 1 overriding asynchronous master reset input (MR)
*/
My4017::My4017(std::string name) : AComponent(name)
{
    _pins = {
        {1, CREATE_OUTPUT},
        {2, CREATE_OUTPUT},
        {3, CREATE_OUTPUT},
        {4, CREATE_OUTPUT},
        {5, CREATE_OUTPUT},
        {6, CREATE_OUTPUT},
        {7, CREATE_OUTPUT},
        {8, CREATE_OUTPUT},
        {9, CREATE_OUTPUT},
        {10, CREATE_OUTPUT},
        {11, CREATE_OUTPUT},
        {12, CREATE_OUTPUT},
        {13, CREATE_INPUT},
        {14, CREATE_INPUT},
        {15, CREATE_INPUT},
    };
}

/**
 * @brief Simulates the component starting from the subcomponents
 * @details If the component is not correctly set up, returns
 * @param currentName The name of the current component
*/
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

/**
 * @brief Resets the component
 * @details Sets the current output to 0 and sets the output pins to False
*/
void My4017::handleReset()
{
    _currentOutput = 0;
    for (int i = 1; i <= 11; i++) {
        _pins[i]->setState(False);
    }
    _pins[3]->setState(True);
    _pins[12]->setState(True);
}
