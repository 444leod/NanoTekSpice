/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4512
*/

#pragma once

#include "../AComponent.hpp"

/**
 * @brief My4512 class
 * @details The 4512 is a 8-channel data selector that can output a Tristate (Undefined, 0, 1)
*/
class My4512 : public nts::AComponent {
    public:
        My4512(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
        void adrressInputs();
};
