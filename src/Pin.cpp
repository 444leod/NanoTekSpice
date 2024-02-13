/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Pin
*/

#include "Pin.hpp"

nts::Pin::Pin(nts::Tristate value)
{
    _value = value;
}

void nts::Pin::setValue(nts::Tristate value)
{
    _value = value;
}

nts::Tristate nts::Pin::getValue() const
{
    return _value;
}