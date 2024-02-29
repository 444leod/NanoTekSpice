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
        void linkSubComponents() override;

    protected:
    private:
};
