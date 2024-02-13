/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Pin
*/

#pragma once

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class Pin {
        public:
            Pin(nts::Tristate value);
            void setValue(nts::Tristate value);
            nts::Tristate getValue() const;

        private:
            nts::Tristate _value;
    };
};
