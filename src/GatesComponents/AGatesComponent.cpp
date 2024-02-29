/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AGatesComponent
*/

#include "AGatesComponent.hpp"

/**
 * @brief Constructor of AGatesComponent
 * @details Used to initialize the pins of the component
*/
AGatesComponent::AGatesComponent(std::string name) : AComponent(name)
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
        {14, CREATE_IGNORED}
    };
}

void AGatesComponent::subSimulate(std::string currentName)
{
    for (auto &subComponent : _subComponents) {
        subComponent.second->subSimulate(currentName);
    }
}
