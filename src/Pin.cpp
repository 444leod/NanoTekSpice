/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Pin
*/

#include "Pin.hpp"

nts::Pin::Pin(nts::PinType type, nts::Tristate state, bool isLocked, bool isIgnored)
{
    _state = state;
    _type = type;
    _isLocked = isLocked;
    _isIgnored = isIgnored;
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

bool nts::Pin::isLocked() const
{
    return _isLocked;
}

bool nts::Pin::isIgnored() const
{
    return _isIgnored;
}
