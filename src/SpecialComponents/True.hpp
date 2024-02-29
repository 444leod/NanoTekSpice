/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** True
*/

#pragma once

#include "./ASpecialComponent.hpp"

namespace nts {
    namespace components {
        /**
         * @brief True class
         * @details This component is always true
        */
        class True : public ASpecialComponent {
            public:
                True(std::string name);

            protected:
            private:
        };
    }
}


