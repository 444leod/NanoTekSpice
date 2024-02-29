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
*/
class And : public AElementaryComponent {
    public:
        And(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
