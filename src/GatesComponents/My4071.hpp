/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4071
*/

#pragma once

#include "./AGatesComponent.hpp"

/**
 * @brief My4071 class
 * @details The 4071 component is a quad 2-input OR gate
*/
class My4071 : public AGatesComponent {
    public:
        My4071(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
