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
        ~GatesComponent();
        void simulate() override;

    protected:
        std::vector<std::shared_ptr<nts::IComponent>> _subComponents = {};
    private:
};
