/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4011
*/

#pragma once

#include "./AGatesComponent.hpp"

class My4011 : public AGatesComponent {
    public:
        My4011(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
