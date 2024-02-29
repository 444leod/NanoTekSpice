/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Not
*/

#pragma once

#include "./AElementaryComponent.hpp"

class Not : public AElementaryComponent {
    public:
        Not(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
