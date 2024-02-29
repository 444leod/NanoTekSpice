/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Or
*/

#include "Or.hpp"

Or::Or(std::string name) : AElementaryComponent(name)
{
}

/**
 * @brief Simulate the Or gate
 * @details Handles the UNDEFINED state
*/
void Or::subSimulate(std::string currentName)
{
    (void)currentName;

    nts::Tristate a = _pins[1] ? _pins[1]->getState() : UNDEFINED;
    nts::Tristate b = _pins[2] ? _pins[2]->getState() : UNDEFINED;

    switch (a) {
        case TRUE:
            setPinValue(3, TRUE);
            break;
        case FALSE:
            switch (b) {
                case TRUE:
                    setPinValue(3, TRUE);
                    break;
                case FALSE:
                    setPinValue(3, FALSE);
                    break;
                case UNDEFINED:
                    setPinValue(3, UNDEFINED);
                    break;
            }
            break;
        case UNDEFINED:
            if (b == TRUE) {
                setPinValue(3, TRUE);
            } else {
                setPinValue(3, UNDEFINED);
            }
            break;
    }
}
