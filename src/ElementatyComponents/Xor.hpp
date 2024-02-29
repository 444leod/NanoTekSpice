/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Xor
*/

#pragma once

#include "./AElementaryComponent.hpp"

class Xor : public AElementaryComponent {
    public:
        Xor(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
