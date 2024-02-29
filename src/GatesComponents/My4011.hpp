/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4011
*/

#pragma once

#include "./GatesComponent.hpp"

class My4011 : public GatesComponent {
    public:
        My4011(std::string name);
        ~My4011();
        void linkSubComponents() override;

    protected:
    private:
};
