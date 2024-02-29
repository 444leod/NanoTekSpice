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
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
