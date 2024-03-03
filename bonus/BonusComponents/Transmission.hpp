/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Transmission
*/

#pragma once

#include "ABonusComponent.hpp"

/**
 * @brief Transmission class
 * @details The Transmission class is used to process a nor gate
*/
class Transmission : public ABonusComponent {
    public:
        Transmission(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
};

