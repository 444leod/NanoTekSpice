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
        ~My4069();
        void simulate() override;

    protected:
    private:
};
