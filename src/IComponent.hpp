/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponent
*/

#pragma once

#include "nanotekspice.hpp"
#include "Pin.hpp"

namespace nts {
    /**
     * @brief IComponent class
     * @details This class is the interface for all components
    */
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(std::string currentName) = 0;
            virtual void subSimulate(std::string currentName) = 0;
            virtual void setPinValue(std::size_t pin, nts::Tristate value) = 0;
            virtual nts::Tristate getPinValue(std::size_t pin) const = 0;
            virtual std::string getName() const = 0;
            virtual std::shared_ptr<Pin> getPin(std::size_t pin) = 0;
            virtual void throwLinkException(
                std::string error,
                std::size_t pin,
                std::string otherName,
                std::size_t otherPin) const = 0;
            virtual void setLink(
                std::size_t pin,
                std::shared_ptr<IComponent> other,
                std::size_t otherPin) = 0;
            virtual void forceSetLink(std::shared_ptr<Pin> pin, std::size_t pinIndex) = 0;
            virtual bool isInput() const = 0;
            virtual int getId() const = 0;
            virtual void linkSubComponents() = 0;
            virtual void dump() = 0;
            /**
             * @brief Exception class for link error
             * @details This class is used to throw an exception when a link error occured
            */
            class LinkException : public std::exception {
                public:
                    LinkException(std::string const &message) : _message(message) {}
                    const char *what() const noexcept override { return _message.c_str(); }
                private:
                    std::string _message;
            };
        protected:
    };
}
