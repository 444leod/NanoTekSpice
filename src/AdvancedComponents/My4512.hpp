/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4512
*/

#pragma once

#include "../AComponent.hpp"

class My4512 : public nts::AComponent {
    public:
        My4512(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
        void adrressInputs();
};
