/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** False
*/

#pragma once

#include "./SpecialComponent.hpp"

namespace nts {
    namespace components {
        /**
         * @brief False class
         * @details This component is always false
        */
        class False : public SpecialComponent {
            public:
                False(std::string name);

            protected:
            private:
        };
    }
}

