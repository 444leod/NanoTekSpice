/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** And
*/

#pragma once

#include "./AElementaryComponent.hpp"

class And : public AElementaryComponent {
    public:
        And(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
