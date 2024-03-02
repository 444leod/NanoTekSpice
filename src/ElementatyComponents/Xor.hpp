/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Xor
*/

#pragma once

#include "./AElementaryComponent.hpp"

/**
 * @brief Xor class
 * @details Basic XOR logic gate
 * Gives true if only one input is true else false
*/
class Xor : public AElementaryComponent {
    public:
        Xor(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
