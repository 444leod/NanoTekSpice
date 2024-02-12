/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Display
*/

#pragma once

#include "ACommand.hpp"

class Display : public ACommand {
    public:
        void execute() final;

    private:
        std::string _command = "display";
};
