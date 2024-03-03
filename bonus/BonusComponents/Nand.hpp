/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Nand
*/

#pragma once

#include "ABonusComponent.hpp"

/**
 * @brief Nand class
 * @details The Nand class is used to process a nand gate
*/
class Nand : public ABonusComponent {
    public:
        Nand(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};

