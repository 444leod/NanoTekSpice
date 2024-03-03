/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Xnor
*/

#pragma once

#include "ABonusComponent.hpp"

/**
 * @brief Xnor class
 * @details The Xnor class is used to process a xnor gate
*/
class Xnor : public ABonusComponent {
    public:
        Xnor(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};

