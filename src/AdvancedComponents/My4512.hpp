/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4512
*/

#pragma once

#include "../AComponent.hpp"

class My4512 : public nts::AComponent {
    public:
        My4512(std::string name);
        ~My4512() = default;
        void simulate() override;

    protected:
    private:
};