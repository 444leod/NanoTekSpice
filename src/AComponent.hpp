/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent
*/

#pragma once

#include "nanotekspice.hpp"
#include "IComponent.hpp"
#include "Pin.hpp"
#include <map>

class AComponent: nts::IComponent {
    public:
        virtual ~AComponent() = default;
        AComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        void setLink(
            std::size_t pin,
            nts::IComponent &other,
            std::size_t otherPin) = 0;
        virtual void dump() const = 0;
        virtual void setPinValue(std::size_t pin, nts::Tristate value) = 0;
        virtual nts::Tristate getPinValue(std::size_t pin) const = 0;

    protected:
        std::unordered_map<std::size_t, nts::Pin> _pins;

};
