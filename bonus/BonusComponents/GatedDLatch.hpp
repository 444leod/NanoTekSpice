/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** GatedDLatch
*/

#pragma once

#include "ABonusComponent.hpp"

/**
 * @brief GatedDLatch class
 * @details The GatedDLatch class is used to process a GatedDLatch gate
*/
class GatedDLatch : public ABonusComponent {
    public:
        GatedDLatch(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};

