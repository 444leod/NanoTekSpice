/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** True
*/

#pragma once

#include "./SpecialComponent.hpp"

namespace nts {
    namespace components {
        /**
         * @brief True class
         * @details This component is always true
        */
        class True : public SpecialComponent {
            public:
                True(std::string name);

            protected:
            private:
        };
    }
}


