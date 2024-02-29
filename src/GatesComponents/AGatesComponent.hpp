/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** AGatesComponent
*/

#pragma once

#include "../AComponent.hpp"

class AGatesComponent : public nts::AComponent {
    public:
        AGatesComponent(std::string name);
        virtual void subSimulate(std::string currentName) override;

    protected:
    private:
};
