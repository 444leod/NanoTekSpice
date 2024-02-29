/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Or
*/

#pragma once

#include "./ElementaryComponent.hpp"

class Or : public ElementaryComponent {
    public:
        Or(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
