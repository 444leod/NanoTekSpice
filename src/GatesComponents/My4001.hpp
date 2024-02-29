/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4001
*/

#pragma once

#include "./AGatesComponent.hpp"

/**
 * @brief My4001 class
 * @details The 4001 component is a quad 2-input NOR gate
*/
class My4001 : public AGatesComponent {
    public:
        My4001(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
