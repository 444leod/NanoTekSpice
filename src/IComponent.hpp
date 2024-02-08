/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent
*/

#pragma once

#include "nanotekspice.hpp"

namespace nts {
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate() = 0;
            virtual void dump() const = 0;
    };
}


