/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** And
*/

#include "And.hpp"

And::And(std::string name) : AElementaryComponent(name)
{
}

/**
 * @brief Simulate the And gate
 * @details Handles the UNDEFINED state
*/
void And::subSimulate(std::string currentName)
{
    (void)currentName;

    nts::Tristate a = getPin(1) ? getPin(1)->getState() : UNDEFINED;
    nts::Tristate b = getPin(2) ? getPin(2)->getState() : UNDEFINED;

    switch (a) {
        case FALSE:
            setPinValue(3, FALSE);
            break;
        case TRUE:
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
            if (b == FALSE) {
                setPinValue(3, FALSE);
            } else {
                setPinValue(3, UNDEFINED);
            }
            break;
    }
}
