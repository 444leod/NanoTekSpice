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

    namespace nts {
        class IComponent;
        class NanoTekSpice;
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

