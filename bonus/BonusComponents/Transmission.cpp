/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Transmission
*/

#include "Transmission.hpp"

/**
 * @brief Transmission class
 * @details The Transmission class is used to process a nor gate
 * a Transmission is a gate with 2 inputs and 1 output
*/
Transmission::Transmission(std::string name) : ABonusComponent(name)
{
    _pins = {
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_OUTPUT}
    };
}

/**
 * @brief Simulates the component starting from the subcomponents
 * @param currentName The name of the current component
*/
void Transmission::subSimulate(std::string currentName)
{
    (void)currentName;

    nts::Tristate A = _pins[1]->getState();
    nts::Tristate B = _pins[2]->getState();

    if (B == TRUE) {
        _pins[3]->setState(A);
    } else {
        _pins[3]->setState(UNDEFINED);
    }
}
