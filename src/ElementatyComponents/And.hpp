/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** And
*/

#pragma once

#include "./ElementaryComponent.hpp"

class And : public ElementaryComponent {
    public:
        And(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
