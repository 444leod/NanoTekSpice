/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#pragma once

#include "nanotekspice.hpp"
#include "IComponent.hpp"
#include "Parser.hpp"
#include "Shell.hpp"
#include "IComponentFactory.hpp"

namespace nts {
    /**
     * @brief NanoTekSpice class
     * @details This class is the main class of the program
    */
    class NanoTekSpice {
        public:
            int run(int argc, const char *argv[]);

        private:
            void bindChipsets();

            std::vector<std::shared_ptr<nts::IComponent>> _components = {};

            std::vector<std::pair<std::string, std::string>> _links = {};
            std::vector<std::pair<std::string, std::string>> _chipsets = {};

            std::vector<std::shared_ptr<nts::IComponent>> _inputs = {};
            std::vector<std::shared_ptr<nts::IComponent>> _outputs = {};
            std::vector<std::shared_ptr<nts::IComponent>> _clocks = {};
            std::vector<std::shared_ptr<nts::IComponent>> _loggers = {};

        };
}
