/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4081
*/

#pragma once

#include "./AGatesComponent.hpp"

class My4081 : public AGatesComponent {
    public:
        My4081(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
