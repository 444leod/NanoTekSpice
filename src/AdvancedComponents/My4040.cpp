/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4040
*/

#include "My4040.hpp"

using nts::Tristate::False;
using nts::Tristate::True;
using nts::Tristate::Undefined;

/**
 * @brief My4040 class constructor
 * @details Has 16 pins: 2 inputs, 12 outputs and 2 ignored
*/
My4040::My4040(std::string name) : AComponent(name)
{
    _pins = {
        {1, CREATE_OUTPUT},
        {2, CREATE_OUTPUT},
        {3, CREATE_OUTPUT},
        {4, CREATE_OUTPUT},
        {5, CREATE_OUTPUT},
        {6, CREATE_OUTPUT},
        {7, CREATE_OUTPUT},
        {8, CREATE_IGNORED},
        {9, CREATE_OUTPUT},
        {10, CREATE_INPUT},
        {11, CREATE_INPUT},
        {12, CREATE_OUTPUT},
        {13, CREATE_OUTPUT},
        {14, CREATE_OUTPUT},
        {15, CREATE_OUTPUT},
        {16, CREATE_IGNORED}
    };
    std::fill(_counter.begin(), _counter.end(), False);
    /*
        00 bit: 9
        01 bit: 7
        02 bit: 6
        03 bit: 5
        04 bit: 3
        05 bit: 2
        06 bit: 4
        07 bit: 13
        08 bit: 12
        09 bit: 14
        10 bit: 15
        11 bit: 1
    */
}

/**
 * @brief Simulates the component starting from the subcomponents
 * @param currentName The name of the current component
*/
void My4040::subSimulate(std::string currentName)
{
    (void)currentName;

    _lastState = _currentState;
    _currentState = _pins[10]->getState();

    nts::Tristate reset = _pins[11]->getState();

    if (reset == True) {
        std::fill(_counter.begin(), _counter.end(), False);
        _value = 0;
        convertToPins();
    } else if (_lastState == True && _currentState == False) {
        _value++;
        if (_value == 4096)
            _value = 0;
    }
    convertToPins();
}

/**
 * @brief Converts the value to pins
 * @details Converts the value to pins using bitwise operations
*/
void My4040::convertToPins()
{
    std::array<std::shared_ptr<nts::Pin>, 12> _outputPins = {
        _pins[9], _pins[7], _pins[6], _pins[5], _pins[3], _pins[2], _pins[4],
        _pins[13], _pins[12], _pins[14], _pins[15], _pins[1]
    };
    for (int i = 0; i < 12; i++) {
        _counter[i] = (_value & (1 << i)) ? True : False;
    }
    for (int i = 0; i < 12; i++) {
        _outputPins[i]->setState(_counter[i]);
    }
}
