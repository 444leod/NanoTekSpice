/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Nor
*/

#pragma once

#include "ABonusComponent.hpp"

/**
 * @brief Nor class
 * @details The Nor class is used to process a nor gate
*/
class Nor : public ABonusComponent {
    public:
        Nor(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};

