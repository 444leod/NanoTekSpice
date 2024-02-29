/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** NanoTekSpice.hpp
*/

#pragma once

    #include <iostream>
    #include <memory>
    #include <vector>
    #include <unordered_map>
    #include <map>
    #include <fstream>
    #include <string>
    #include <sstream>
    #include <algorithm>
    #include <functional>
    #include <csignal>
    #include <filesystem>

    #define CREATE_INPUT std::make_shared<nts::Pin>(this, nts::PinType::INPUT, nts::Tristate::Undefined)
    #define CREATE_OUTPUT std::make_shared<nts::Pin>(this, nts::PinType::OUTPUT, nts::Tristate::Undefined)
    #define CREATE_IGNORED std::make_shared<nts::Pin>(this, nts::PinType::OUTPUT, nts::Tristate::Undefined, false, true)

    namespace nts {
        inline int currentTick = 0;
        class IComponent;
        class NanoTekSpice;
        class Parser;
        class Pin;
        enum Tristate {
            Undefined = (-true),
            True = true,
            False = false
        };
            #define TRUE nts::Tristate::True
            #define FALSE nts::Tristate::False
            #define UNDEFINED nts::Tristate::Undefined
    }

