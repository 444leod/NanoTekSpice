/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4081
*/

#pragma once

#include "./GatesComponent.hpp"

class My4081 : public GatesComponent {
    public:
        My4081(std::string name);
        ~My4081();
        void simulate() override;

    protected:
    private:
};
