/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Pin
*/

#pragma once

#include "nanotekspice.hpp"

namespace nts {

    enum PinType {
        INPUT,
        OUTPUT,
    };


    /**
     * @brief Pin class
     * @details This class is used to store the state of a pin, it's type and if it's locked or ignored
    */
    class Pin {
        public:
            Pin(nts::PinType type, nts::Tristate state = nts::Tristate::Undefined, bool isLocked = false, bool isIgnored = false);
            ~Pin() = default;
            /**
             * @brief Exception class for assignment error
             * @details This class is used to throw an exception when an assignment error occured
            */
            class AssignmentError : public std::exception {
                public:
                    AssignmentError(std::string const &message) : _message(message) {};
                    const char *what() const noexcept override { return _message.c_str(); };
                private:
                    std::string _message;
            };
            void setState(nts::Tristate state);
            nts::Tristate getState() const;
            nts::PinType getType() const;
            bool isLocked() const;
            bool isIgnored() const;

        protected:
        private:
            nts::Tristate _state;
            nts::PinType _type;
            bool _isLocked = false;
            bool _isIgnored = false;
    };
}

