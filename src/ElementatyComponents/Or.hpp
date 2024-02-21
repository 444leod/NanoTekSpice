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
        ~Or();
        void simulate() override;

    protected:
    private:
};
