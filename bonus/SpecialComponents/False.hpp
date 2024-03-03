/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** False
*/

#pragma once

#include "./ASpecialComponent.hpp"

namespace nts {
    namespace components {
        /**
         * @brief False class
         * @details This component is always false
        */
        class False : public ASpecialComponent {
            public:
                False(std::string name);

            protected:
            private:
        };
    }
}

