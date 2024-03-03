/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Not
*/

#pragma once

#include "./AElementaryComponent.hpp"

/**
 * @brief Not class
 * @details Basic NOT logic gate
 * Gives the opposite of the input
*/
class Not : public AElementaryComponent {
    public:
        Not(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
