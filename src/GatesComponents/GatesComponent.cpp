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
        {1, CREATE_INPUT},
        {2, CREATE_INPUT},
        {3, CREATE_OUTPUT},
        {4, CREATE_OUTPUT},
        {5, CREATE_INPUT},
        {6, CREATE_INPUT},
        {7, CREATE_IGNORED},
        {8, CREATE_INPUT},
        {9, CREATE_INPUT},
        {10, CREATE_OUTPUT},
        {11, CREATE_OUTPUT},
        {12, CREATE_INPUT},
        {13, CREATE_INPUT},
        {14,  CREATE_IGNORED}
    };
}

GatesComponent::~GatesComponent()
{
}

void GatesComponent::subSimulate(std::string currentName)
{
    for (auto &subComponent : _subComponents) {
        subComponent.second->subSimulate(currentName);
    }
}
