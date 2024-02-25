/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4008
*/

#pragma once

#include "../AComponent.hpp"

class My4008 : public nts::AComponent {
    public:
        My4008(std::string name);
        ~My4008() = default;
        void simulate() override;

    protected:
    private:
};
