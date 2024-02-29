/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4081
*/

#pragma once

#include "./AGatesComponent.hpp"

/**
 * @brief My4081 class
 * @details The 4081 component is a quad 2-input AND gate
*/
class My4081 : public AGatesComponent {
    public:
        My4081(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
