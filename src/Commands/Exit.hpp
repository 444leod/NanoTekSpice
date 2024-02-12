/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Exit
*/

#pragma once

#include "./ACommand.hpp"

class Exit : public ACommand {
    public:
        void execute() override;

    private:
        std::string _command = "exit";
};
