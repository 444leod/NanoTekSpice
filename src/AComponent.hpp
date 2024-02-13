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

namespace nts {
    class AComponent: public nts::IComponent {
        public:
            virtual void simulate(std::size_t tick);
            virtual nts::Tristate compute(std::size_t pin);
            virtual void setLink(
                std::size_t pin,
                nts::IComponent &other,
                std::size_t otherPin);
            virtual void dump() const;
            virtual void setPinValue(std::size_t pin, nts::Tristate value);
            virtual nts::Tristate getPinValue(std::size_t pin) const;

        protected:
            std::unordered_map<std::size_t, nts::IComponent> _pins;
    };
};