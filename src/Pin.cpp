/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Pin
*/

#include "Pin.hpp"

nts::Pin::Pin(nts::PinType type, nts::Tristate state, bool isLocked)
{
    _state = state;
    _type = type;
    _isLocked = isLocked;
}

void nts::Pin::setState(nts::Tristate state)
{
    if (!_isLocked)
        _state = state;
    else
        throw nts::AssignmentError("Pin is locked");
}

nts::Tristate nts::Pin::getState() const
{
    return _state;
}

nts::PinType nts::Pin::getType() const
{
    return _type;
}
