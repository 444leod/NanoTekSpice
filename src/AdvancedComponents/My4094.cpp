/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4094
*/

#include "My4094.hpp"

using nts::Tristate::False;
using nts::Tristate::True;
using nts::Tristate::Undefined;

/**
 * @brief My4094 class constructor
 * @details Has 16 pins: 4 input pins, 10 output pins, 2 ignored (VSS & VDD)
 * 1 input pin for the clock, 1 input pin for the data,
 * 1 input pin for the strobe, 1 input pin for the enable
*/
My4094::My4094(std::string name) : AComponent(name)
{
    _pins = {
        {1,  CREATE_INPUT},
        {2,  CREATE_INPUT},
        {3,  CREATE_INPUT},
        {4,  CREATE_OUTPUT},
        {5,  CREATE_OUTPUT},
        {6,  CREATE_OUTPUT},
        {7,  CREATE_OUTPUT},
        {8,  CREATE_IGNORED},
        {9,  CREATE_OUTPUT},
        {10, CREATE_OUTPUT},
        {11, CREATE_OUTPUT},
        {12, CREATE_OUTPUT},
        {13, CREATE_OUTPUT},
        {14, CREATE_OUTPUT},
        {15, CREATE_INPUT},
        {16, CREATE_IGNORED}
    };
}

/**
 * @brief Links the subcomponents of the current component
 * @details Initialize the list of outputs.
*/
void My4094::linkSubComponents()
{
    _qPins = {
        _pins[4],
        _pins[5],
        _pins[6],
        _pins[7],
        _pins[14],
        _pins[13],
        _pins[12],
        _pins[11]
    };
}

/**
 * @brief Simulates the component starting from the subcomponents
 * @details Handles the low to high and high to low transitions
 * @param currentName The name of the current component
*/
void My4094::subSimulate(std::string currentName)
{
    (void)currentName;

    _lastState = _actualState;
    _actualState = _pins[3]->getState();
    nts::Tristate strobe = _pins[1]->getState();
    nts::Tristate data = _pins[2]->getState();
    nts::Tristate enable = _pins[15]->getState();

    if (_lastState == False && _actualState == True) {
        lowToHigh(strobe, data, enable);
    } else if (_lastState == True && _actualState == False) {
        highToLow(strobe, data, enable);
    }
}

/**
 * @brief Simulates the low to high transition of the component
 * @details Handles the low to high transition following the 4094 truth table
 * @param strobe The state of the strobe pin
 * @param data The state of the data pin
 * @param enable The state of the enable pin
*/
void My4094::lowToHigh(nts::Tristate strobe, nts::Tristate data, nts::Tristate enable)
{
    if (data == True && strobe == True && enable == True) {
        for (int i = 1; i < 8; i++) {
            _qPins[i]->setState(_qPins[i - 1]->getState());
        }
        _qPins[0]->setState(TRUE);
        _pins[9]->setState(_qPins[7]->getState());
    } else if (data == False && strobe == True && enable == True) {
        for (int i = 1; i < 8; i++) {
            _qPins[i]->setState(_qPins[i - 1]->getState());
        }
        _qPins[0]->setState(FALSE);
        _pins[9]->setState(_qPins[7]->getState());
    } else if (strobe == False && enable == True) {
        _pins[9]->setState(_qPins[7]->getState());
    } else if (enable == false) {
        for (int i = 0; i < 8; i++) {
            if (_qPins[i])
                _qPins[i]->setState(Undefined);
        }
        _pins[9]->setState(Undefined);
    }
}

/**
 * @brief Simulates the high to low transition of the component
 * @details Handles the high to low transition following the 4094 truth table
 * @param strobe The state of the strobe pin
 * @param data The state of the data pin
 * @param enable The state of the enable pin
*/
void My4094::highToLow(nts::Tristate strobe, nts::Tristate data, nts::Tristate enable)
{
    if (data == True && strobe == True && enable == True) {
        _pins[10]->setState(_qPins[6]->getState());
    } else if (data == False && strobe == True && enable == True) {
        for (int i = 7; i > 0; i--) {
            _qPins[i - 1]->setState(_qPins[i]->getState());
        }
        _qPins[7]->setState(FALSE);
        _pins[9]->setState(_qPins[7]->getState());
    } else if (strobe == False && enable == True) {
        _pins[9]->setState(_qPins[7]->getState());
    } else if (enable == false) {
        for (int i = 0; i < 8; i++) {
            if (_qPins[i])
                _qPins[i]->setState(Undefined);
        }
        _pins[9]->setState(Undefined);
    }
}
