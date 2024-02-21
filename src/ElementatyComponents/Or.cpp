/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Or
*/

#include "Or.hpp"

Or::Or(std::string name) : ElementaryComponent(name)
{
}

Or::~Or()
{
}

void Or::simulate()
{
    nts::Tristate a = getPin(1) ? getPin(1)->getState() : UNDEFINED;
    nts::Tristate b = getPin(2) ? getPin(2)->getState() : UNDEFINED;

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
