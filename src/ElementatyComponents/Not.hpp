/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Not
*/

#pragma once

#include "./ElementaryComponent.hpp"

class Not : public ElementaryComponent {
    public:
        Not(std::string name);
        ~Not();
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
