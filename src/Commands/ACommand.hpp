/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ACommand
*/

#pragma once

#include "../ICommand.hpp"

class ACommand : public ICommand {
    public:
        std::string getCommand() const override;

    protected:
    private:
        std::string _command = "none";
};
