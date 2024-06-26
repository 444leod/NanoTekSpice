/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Pin
*/

#include "Pin.hpp"

nts::Pin::Pin(IComponent *component, nts::PinType type, nts::Tristate state, bool isLocked, bool isIgnored)
{
    _state = state;
    _type = type;
    _isLocked = isLocked;
    _isIgnored = isIgnored;
    _linkedComponent = component;
}


/**
 * @brief Set the state of the pin
 * @details This function is used to set the state of the pin
 * @throws AssignmentError if the pin is locked
*/
void nts::Pin::setState(nts::Tristate state)
{
    if (!_isLocked)
        _state = state;
    else
        throw nts::Pin::AssignmentError("Pin is locked");
}

/**
 * @brief Get the state of the pin
 * @details This function is used to get the state of the pin
 * @return The state of the pin
*/
nts::Tristate nts::Pin::getState() const
{
    if (_linkedPin != nullptr)
        return _linkedPin->getState();
    return _state;
}

nts::PinType nts::Pin::getType() const
{
    return _type;
}

bool nts::Pin::isIgnored() const
{
    return _isIgnored;
}

/**
 * @brief Set the link of the pin
 * @throws AssignmentError if the pin is already linked
*/
void nts::Pin::setLink(std::shared_ptr<Pin> pin)
{
    if (_linkedPin != nullptr)
        throw nts::Pin::AssignmentError("Pin is already linked");
    _linkedPin = pin;
}

/**
 * @brief Set the link of the pin
 * @details if the _linkedPin is not null then call it's simulate method
*/
void nts::Pin::simulate(std::string currentName)
{
    if (_linkedPin != nullptr) {
        _linkedPin->simulate(currentName);
        return;
    }
    _linkedComponent->simulate(currentName);
}
