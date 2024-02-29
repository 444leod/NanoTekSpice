/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4030
*/

#pragma once

#include "./GatesComponent.hpp"

class My4030 : public GatesComponent {
    public:
        My4030(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
