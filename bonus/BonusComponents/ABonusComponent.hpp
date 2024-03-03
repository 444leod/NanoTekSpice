/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ABonusComponent
*/

#pragma once

#include "../AComponent.hpp"

/**
 * @brief ABonusComponent class
 * @details Represents the abstract class for elementary components
*/
class ABonusComponent : public nts::AComponent {
    public:
        ABonusComponent(std::string name) : AComponent(name) {};

    protected:
    private:
};
