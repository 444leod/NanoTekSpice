/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** SRLatch
*/

#pragma once

#include "ABonusComponent.hpp"

/**
 * @brief SRLatch class
 * @details The SRLatch class is used to process a SRLatch gate
 * a SRLatch is a gated latch with two inputs, S and R, and two outputs, Q and Qnot
 * The S and R stand for Set and Reset, respectively
*/
class SRLatch : public ABonusComponent {
    public:
        SRLatch(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};

