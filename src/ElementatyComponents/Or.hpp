/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Or
*/

#pragma once

#include "./AElementaryComponent.hpp"

/**
 * @brief Or class
 * @details Basic OR logic gate
 * Gives true if at least one input is true else false
*/
class Or : public AElementaryComponent {
    public:
        Or(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
