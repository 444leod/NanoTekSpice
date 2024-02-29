/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AGatesComponent
*/

#pragma once

#include "../AComponent.hpp"

/**
 * @brief AGatesComponent class
 * @details Represents the abstract class for gate components
*/
class AGatesComponent : public nts::AComponent {
    public:
        AGatesComponent(std::string name);
        virtual void subSimulate(std::string currentName) override;

    protected:
    private:
};
