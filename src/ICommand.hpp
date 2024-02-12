/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ICommand
*/

#pragma once

#include "nanotekspice.hpp"

class ICommand {
    public:
        ~ICommand() = default;
        virtual void execute() = 0; //add all components as parameter
        virtual std::string getCommand() const = 0;

    protected:
    private:
};
