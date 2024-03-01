/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4008
*/

#pragma once

#include "../AComponent.hpp"

/**
 * @brief My4008 class
 * @details The 4008 is a 4-bit adder
*/
class My4008 : public nts::AComponent {
    public:
        My4008(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
