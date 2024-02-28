/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AComponent
*/

#include "AComponent.hpp"

int nts::AComponent::nextId = 0;

nts::AComponent::AComponent(std::string name)
{
    _name = name;
    _id = nextId++;
}

nts::AComponent::~AComponent()
{
}

std::string nts::AComponent::getName() const
{
    return _name;
}

void nts::AComponent::simulate()
{
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
    if (_id == other->getId())
        throw nts::IComponent::LinkException("Cannot link a component to itself");
    if (_pins.find(pin) == _pins.end())
        throw nts::IComponent::LinkException(
            "Pin not found ( linking pin " + std::to_string(pin) + "from " +
            _name + " to " + other->getName() + " pin " + std::to_string(otherPin)
        );

    std::shared_ptr<Pin> pin1 = _pins[pin];
    std::shared_ptr<Pin> pin2 = other->getPin(otherPin);

    if ((pin1 == NULL && pin2 == NULL))
        throw nts::IComponent::LinkException(
            "Both pins are input pins (linking pin " + std::to_string(pin) + " from " +
            _name + " to " + other->getName() + " pin " + std::to_string(otherPin) + ")"
        );

    if ((pin1 && pin1->isIgnored()) || (pin2 && pin2->isIgnored()))
        throw nts::IComponent::LinkException(
            "One of the pins is ignored (linking pin " + std::to_string(pin) + " from " +
            _name + " to " + other->getName() + " pin " + std::to_string(otherPin) + ")"
        );

    if (pin1 == NULL) {
        _pins[pin] = pin2;
    } else if (pin2 == NULL) {
        other->forceSetLink(_pins[pin], otherPin);
    } else {
        throw nts::IComponent::LinkException(
            "Pins are outputs (linking pin " + std::to_string(pin) + " from " +
            _name + " to " + other->getName() + " pin " + std::to_string(otherPin) + ")"
        );
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
    _pins.at(pinIndex) = pin;
}

bool nts::AComponent::isInput() const
{
    return _isInput;
}

int nts::AComponent::getId() const
{
    return _id;
}
