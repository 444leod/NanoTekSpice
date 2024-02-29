/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4071
*/

#pragma once

#include "./GatesComponent.hpp"

class My4071 : public GatesComponent {
    public:
        My4071(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
