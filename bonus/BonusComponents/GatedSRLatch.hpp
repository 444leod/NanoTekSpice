/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** GatedSRLatch
*/

#pragma once

#include "ABonusComponent.hpp"

/**
 * @brief GatedSRLatch class
 * @details The GatedSRLatch class is used to process a GatedSRLatch gate
 * a GatedSRLatch is a gated latch with 3 inputs, R, S and E, and 2 outputs, Q and Qnot
 * The S and R stand for Set and Reset, respectively
 * The E stands for Enable
*/
class GatedSRLatch : public ABonusComponent {
    public:
        GatedSRLatch(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};

