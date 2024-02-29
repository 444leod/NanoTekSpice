/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4011
*/

#pragma once

#include "./AGatesComponent.hpp"

/**
 * @brief My4011 class
 * @details The 4011 component is a quad 2-input NAND gate
*/
class My4011 : public AGatesComponent {
    public:
        My4011(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
