/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** GatesComponent
*/

#include "GatesComponent.hpp"

GatesComponent::GatesComponent(std::string name) : AComponent(name)
{
    _pins = {
        {1, NULL},
        {2, NULL},
        {3, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},
        {4, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},
        {5, NULL},
        {6, NULL},
        {7, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined, false, true)},
        {8, NULL},
        {9, NULL},
        {10, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},
        {11, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},
        {12, NULL},
        {13, NULL},
        {14,  std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined, false, true)}
    };
}

GatesComponent::~GatesComponent()
{
}

void GatesComponent::simulate()
{
    for (auto &subComponent : _subComponents) {
        subComponent->simulate();
    }
}
