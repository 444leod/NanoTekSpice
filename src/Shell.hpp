/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Shell
*/

#pragma once

#include "nanotekspice.hpp"
#include "IComponent.hpp"

namespace nts {
    /**
     * @brief Shell class
     * @details This class is used to handle the shell
     * It's used to parse the input and execute the commands
    */
    class Shell {
        public:
            Shell(std::vector<
                std::shared_ptr<nts::IComponent>> components,
                std::vector<std::shared_ptr<nts::IComponent>> inputs,
                std::vector<std::shared_ptr<nts::IComponent>> outputs,
                std::vector<std::shared_ptr<nts::IComponent>> clocks);
            ~Shell() = default;
            /**
             * @brief Exception class for parsing error
             * @details This class is used to throw an exception when a parsing error occured
            */
            class ParsingError : public std::exception {
                public:
                    ParsingError(const std::string &message) : _message(message) {}
                    const char *what() const noexcept override { return _message.c_str(); }
                private:
                    std::string _message;
            };
            int run();
        private:
            void exit();
            void display();
            void simulate();
            void loop();
            void sd();
            void assign(const std::string &s, std::stringstream &ss);
            const std::unordered_map<std::string, std::function<void()>> _commands = {
                {"exit", [&]() { exit(); }},
                {"display", [&]() { display(); }},
                {"simulate", [&]() { simulate(); }},
                {"loop", [&]() { loop(); }},
                {"sd", [&]() { sd(); }}
            };
            std::vector<std::shared_ptr<nts::IComponent>> _components = {};
            std::vector<std::pair<std::string, std::string>> _assignements = {};

            std::vector<std::shared_ptr<nts::IComponent>> _inputs = {};
            std::vector<std::shared_ptr<nts::IComponent>> _outputs = {};
            std::vector<std::shared_ptr<nts::IComponent>> _clocks = {};

            std::map<nts::Tristate, std::string> _statesToString = {
                {nts::Tristate::Undefined, "U"},
                {nts::Tristate::False, "0"},
                {nts::Tristate::True, "1"}
            };
    };
}
