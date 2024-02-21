/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Xor
*/

#pragma once

#include "./ElementaryComponent.hpp"

class Xor : public ElementaryComponent {
    public:
        Xor(std::string name);
        ~Xor();
        void simulate() override;

    protected:
    private:
};
