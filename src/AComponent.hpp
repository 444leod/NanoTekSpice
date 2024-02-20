/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent
*/

#pragma once

#include "nanotekspice.hpp"
#include "IComponent.hpp"
#include <map>

namespace nts {
    class AComponent: public nts::IComponent {
        public:
            AComponent(std::string name = "AComponent");
            ~AComponent();
            virtual void simulate();
            virtual void setPinValue(std::size_t pin, nts::Tristate value);
            virtual nts::Tristate getPinValue(std::size_t pin) const;
            virtual std::string getName() const;
            virtual std::shared_ptr<nts::Pin> getPin(std::size_t pin);
            virtual void setLink(std::size_t pin, std::shared_ptr<IComponent> other, std::size_t otherPin);
            virtual void forceSetLink(std::shared_ptr<nts::Pin> pin, std::size_t pinIndex);
            virtual bool isInput() const;

        protected:
            std::string _name = "AComponent";
    };
};
