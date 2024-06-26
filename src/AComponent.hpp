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
    /**
     * @brief AComponent class
     * @details This class is the abstract class for all components
    */
    class AComponent: public nts::IComponent {
        public:
            AComponent(std::string name = "AComponent") : self(this), _name(name), _id(nextId++) {};
            ~AComponent();
            virtual void simulate(std::string currentName);
            virtual void subSimulate(std::string currentName);
            virtual void setPinValue(std::size_t pin, nts::Tristate value);
            virtual nts::Tristate getPinValue(std::size_t pin) const;
            virtual std::string getName() const;
            virtual std::shared_ptr<nts::Pin> getPin(std::size_t pin);
            virtual void throwLinkException(
                std::string error,
                std::size_t pin,
                std::string otherName,
                std::size_t otherPin) const final;
            virtual void setLink(
                std::size_t pin,
                std::shared_ptr<IComponent> other,
                std::size_t otherPin);
            virtual void forceSetLink(std::shared_ptr<nts::Pin> pin, std::size_t pinIndex);
            virtual bool isInput() const;
            virtual int getId() const;
            virtual void linkSubComponents();
            virtual void dump();

        protected:
            IComponent *self;
            std::unordered_map<std::size_t, std::shared_ptr<Pin>> _pins = {};
            std::map<std::string, std::shared_ptr<nts::IComponent>> _subComponents = {};
            bool _isInput = false;
            std::vector<std::string> _alreadyTickeds;
            std::string _name = "AComponent";
            int _id;
            static int nextId;
    };
};
