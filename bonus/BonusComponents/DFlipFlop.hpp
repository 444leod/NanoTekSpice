/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** DFlipFlop
*/

#pragma once

#include "ABonusComponent.hpp"
#include "TriInputElementary.hpp"

/**
 * @brief DFlipFlop class
 * @details The DFlipFlop class is used to process a DFlipFlop gate
*/
class DFlipFlop : public ABonusComponent {
    public:
        DFlipFlop(std::string name);
        void linkSubComponents() override;

    protected:
    private:
};
