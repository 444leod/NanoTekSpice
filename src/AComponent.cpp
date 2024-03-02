/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"

using nts::PinType::INPUT;
using nts::PinType::OUTPUT;

int nts::AComponent::nextId = 0;

nts::AComponent::~AComponent()
{
}

std::string nts::AComponent::getName() const
{
    return _name;
}

/**
 * @brief simulate the precious before simulating itself
 * @param currentName - the name of the current component
*/
void nts::AComponent::simulate(std::string currentName)
{
    for (auto &alreadyTicked : _alreadyTickeds) {
        if (alreadyTicked == currentName) {
            return;
        }
    }
   _alreadyTickeds.push_back(currentName);
    for (auto &pin : _pins) {
        if (pin.second != NULL && pin.second->getType() == nts::PinType::INPUT) {
            pin.second->simulate(currentName);
        }
    }
    subSimulate(currentName);
}

void nts::AComponent::subSimulate(std::string currentName)
{
    (void)currentName;
}

/**
 * @brief Set the value of a pin
 * @throws std::out_of_range - if the pin is not found
 * @param pin - the pin to set
 * @param value - the value to attribute to the pin
*/
void nts::AComponent::setPinValue(size_t pin, nts::Tristate value)
{
    if (_pins.find(pin) == _pins.end())
        throw std::out_of_range("Pin not found");
    if (_pins.at(pin) == NULL)
        throw std::out_of_range("Pin not found");
    _pins.at(pin)->setState(value);
}

/**
 * @brief Get the value of a pin
 * @throws std::out_of_range - if the pin is not found
 * @param pin - the pin to get the value from
*/
nts::Tristate nts::AComponent::getPinValue(size_t pin) const
{
    if (_pins.find(pin) == _pins.end())
        throw std::out_of_range("Pin not found");
    if (_pins.at(pin) == NULL)
        return nts::Tristate::Undefined;
    return _pins.at(pin)->getState();
}

/**
 * @brief Get the pin
 * @throws nts::IComponent::LinkException - if the pin is not found
*/
std::shared_ptr<nts::Pin> nts::AComponent::getPin(size_t pin)
{
    if (_pins.find(pin) == _pins.end())
        throw nts::IComponent::LinkException("Pin not found");

    return _pins[pin];
}

/**
 * @brief Throw a link exception
 * @throws nts::IComponent::LinkException - with the error message
 * @param error - the error message
 * @param pin - the pin
 * @param otherName - the name of the other component
 * @param otherPin - the other pin
*/
void nts::AComponent::throwLinkException(
    std::string error,
    size_t pin,
    std::string otherName,
    size_t otherPin) const
{
    std::string message = error + " (linking pin ";
    message += std::to_string(pin);
    message += " from ";
    message += _name;
    message += " to ";
    message += otherName;
    message += " pin ";
    message += std::to_string(otherPin);
    message += ")";

    throw nts::IComponent::LinkException(message);
}

/**
 * @brief Set the link between two components
 * @throws nts::IComponent::LinkException - if:
 * - the component is trying to link to itself
 * - pin is not found 
 * - both pins are inputs
 * - one of the pins is ignored
 * - both pins are outputs
 * @param pin - the pin to link
 * @param other - the component
 * @param otherPin - the other pin to link to
*/
void nts::AComponent::setLink(
    size_t pin,
    std::shared_ptr<IComponent> other,
    size_t otherPin
){
    if (_id == other->getId() && pin == otherPin)
        throw nts::IComponent::LinkException("Cannot link a component to itself");
    if (_pins.find(pin) == _pins.end())
        throwLinkException("Pin not found", pin, other->getName(), otherPin);

    std::shared_ptr<Pin> pin1 = _pins[pin];
    std::shared_ptr<Pin> pin2 = other->getPin(otherPin);

    if ((pin1->getType() == INPUT && pin2->getType() == INPUT))
        throwLinkException("Both pins are input pins", pin, other->getName(), otherPin);

    if ((pin1 && pin1->isIgnored()) || (pin2 && pin2->isIgnored()))
        throwLinkException("One of the pins is ignored", pin, other->getName(), otherPin);

    if (pin1->getType() == INPUT) {
        _pins[pin]->setLink(pin2);
    } else if (pin2->getType() == INPUT){
        other->forceSetLink(_pins[pin], otherPin);
    } else {
        throwLinkException("Pins are outputs", pin, other->getName(), otherPin);
    }
}

/**
 * @brief Force the link between two components
 * @details This function is used to link two components without checking if the link is valid
 * Only use if you are sure the link is valid
 * @param pin - the pin to link
 * @param pinIndex - the index of the pin
*/
void nts::AComponent::forceSetLink(std::shared_ptr<nts::Pin> pin, std::size_t pinIndex)
{
    _pins[pinIndex]->setLink(pin);
}

bool nts::AComponent::isInput() const
{
    return _isInput;
}

int nts::AComponent::getId() const
{
    return _id;
}

void nts::AComponent::linkSubComponents()
{
}

/**
 * @brief Empty the list of already ticked components
*/
void nts::AComponent::dump()
{
    for (auto &subComponent : _subComponents) {
        subComponent.second->dump();
    }
    _alreadyTickeds.clear();
}
