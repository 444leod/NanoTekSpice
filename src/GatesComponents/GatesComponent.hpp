/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** GatesComponent
*/

#pragma once

#include "../AComponent.hpp"

class GatesComponent : public nts::AComponent {
    public:
        GatesComponent(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
