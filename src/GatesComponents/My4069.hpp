/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4069
*/

#pragma once

#include "./GatesComponent.hpp"

class My4069 : public GatesComponent {
    public:
        My4069(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
