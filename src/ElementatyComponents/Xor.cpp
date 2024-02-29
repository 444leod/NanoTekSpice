/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Xor
*/

#include "Xor.hpp"

Xor::Xor(std::string name) : ElementaryComponent(name)
{
}

Xor::~Xor()
{
}

void Xor::subSimulate(std::string currentName)
{
    (void)currentName;

    nts::Tristate a = getPin(1) ? getPin(1)->getState() : UNDEFINED;
    nts::Tristate b = getPin(2) ? getPin(2)->getState() : UNDEFINED;

    switch (a) {
        case TRUE:
            switch (b) {
                case TRUE:
                    setPinValue(3, FALSE);
                    break;
                case FALSE:
                    setPinValue(3, TRUE);
                    break;
                case UNDEFINED:
                    setPinValue(3, UNDEFINED);
                    break;
            }
            break;
        case FALSE:
            switch (b) {
                case FALSE:
                    setPinValue(3, FALSE);
                    break;
                case TRUE:
                    setPinValue(3, TRUE);
                    break;
                case UNDEFINED:
                    setPinValue(3, UNDEFINED);
                    break;
            }
            break;
        case UNDEFINED:
            setPinValue(3, UNDEFINED);
            break;
    }
}
