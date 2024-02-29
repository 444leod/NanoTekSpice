/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** And
*/

#pragma once

#include "./AElementaryComponent.hpp"

/**
 * @brief And class
 * @details Basic AND logic gate
 * Gives true if all inputs are true else false
*/
class And : public AElementaryComponent {
    public:
        And(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
