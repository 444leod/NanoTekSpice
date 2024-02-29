/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Or
*/

#pragma once

#include "./AElementaryComponent.hpp"

class Or : public AElementaryComponent {
    public:
        Or(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};
