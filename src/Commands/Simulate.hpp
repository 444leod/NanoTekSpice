/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Simulate
*/

#pragma once

#include "./ACommand.hpp"

class Simulate : public ACommand {
    public:
        void execute() override;

    private:
        std::string _command = "simulate";
};
