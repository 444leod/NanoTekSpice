/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4030
*/

#pragma once

#include "./AGatesComponent.hpp"

/**
 * @brief My4030 class
 * @details The 4030 component is a quad 2-input XOR gate
*/
class My4030 : public AGatesComponent {
    public:
        My4030(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
