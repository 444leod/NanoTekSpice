/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4001
*/

#pragma once

#include "./AGatesComponent.hpp"

class My4001 : public AGatesComponent {
    public:
        My4001(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
