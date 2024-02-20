/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#pragma once

#include "nanotekspice.hpp"
#include "IComponent.hpp"

#include "./SpecialComponents/Input.hpp"
#include "./SpecialComponents/Output.hpp"
#include "./SpecialComponents/Clock.hpp"
#include "./SpecialComponents/True.hpp"
#include "./SpecialComponents/False.hpp"
#include "./ElementatyComponents/And.hpp"
#include "./ElementatyComponents/Or.hpp"
#include "./ElementatyComponents/Xor.hpp"
#include "./ElementatyComponents/Not.hpp"
#include "./GatesComponents/My4001.hpp"
// #include "./GatesComponents/My4011.hpp"
// #include "./GatesComponents/My4030.hpp"
// #include "./GatesComponents/My4069.hpp"
// #include "./GatesComponents/My4071.hpp"
// #include "./GatesComponents/My4081.hpp"

namespace nts {

    class NanoTekSpice {
        public:
            int run(int argc, const char *argv[]);

            class ParsingError : public std::exception {
                public:
                    ParsingError(const std::string &message) : _message(message) {}
                    const char *what() const noexcept override { return _message.c_str(); }
                private:
                    std::string _message;
            };
            class HelpFlag : public std::exception {
            };

        private:
            void parseArgs(int argc, const char *argv[]);
            void parseFile(const std::string &filename);
            void handleChipset(std::string &line, int lineCount);
            void handleLink(std::string &line, int lineCount);
            void handleNone(std::string &line, int lineCount);
            int shell();

            std::shared_ptr<IComponent> IComponentFactory(std::string componentType, std::string name);

            enum fileState {
                NONE,
                CHIPSETS,
                LINKS
            };

            std::map<std::string, nts::NanoTekSpice::fileState> _states = {
                {".chipsets:", CHIPSETS},
                {".links:", LINKS}
            };
            // std::map<fileState, std::function<void(NanoTekSpice&, std::string&, int)>> _handlers = {
            //     {fileState::NONE, std::mem_fn(&NanoTekSpice::handleNone)},
            //     {fileState::CHIPSETS, std::mem_fn(&NanoTekSpice::handleChipset)},
            //     {fileState::LINKS, std::mem_fn(&NanoTekSpice::handleLink)},
            // };

            std::map<fileState, std::function<void(std::string &, int)>> _handlers = {
                {fileState::NONE, [&](std::string &chipset, int lineCount) { handleNone(chipset, lineCount); }},
                {fileState::CHIPSETS, [&](std::string &chipset, int lineCount) { handleChipset(chipset, lineCount); }},
                {fileState::LINKS, [&](std::string &chipset, int lineCount) { handleLink(chipset, lineCount); }}
            };

            std::map<std::string, std::function<std::shared_ptr<IComponent>(std::string)>> _componentFactory = {
                {"true", [](std::string name) { return std::make_shared<nts::components::True>(name); }},
                {"false", [](std::string name) { return std::make_shared<nts::components::False>(name); }},
                // {"and", [](std::string name) { return std::make_shared<And>(name); }},
                // {"or", [](std::string name) { return std::make_shared<Or>(name); }},
                // {"xor", [](std::string name) { return std::make_shared<Xor>(name); }},
                // {"not", [](std::string name) { return std::make_shared<Not>(name); }},
                // {"4001", [](std::string name) { return std::make_shared<My4001>(name); }},
                // {"4011", [](std::string name) { return std::make_shared<My4011>(name); }},
                // {"4030", [](std::string name) { return std::make_shared<My4030>(name); }},
                // {"4069", [](std::string name) { return std::make_shared<My4069>(name); }},
                // {"4071", [](std::string name) { return std::make_shared<My4071>(name); }},
                // {"4081", [](std::string name) { return std::make_shared<My4081>(name); }},
            };

            void exit();
            void display();
            void simulate();
            void loop();
            void assign(const std::string &s, std::stringstream &ss);

             const std::unordered_map<std::string, std::function<void()>> _commands = {
                {"exit", [&]() { exit(); }},
                {"display", [&]() { display(); }},
                {"simulate", [&]() { simulate(); }},
                {"loop", [&]() { loop(); }},
            };

            std::vector<std::shared_ptr<nts::IComponent>> _components;
            std::vector<std::pair<std::string, std::string>> _assignements = {};
            std::vector<std::pair<std::string, std::string>> _links = {};

            int _tick = 0;
            std::vector<std::shared_ptr<nts::IComponent>> _inputs = {};
            std::vector<std::shared_ptr<nts::IComponent>> _outputs = {};
            std::vector<std::shared_ptr<nts::IComponent>> _clocks = {};

        };
}
