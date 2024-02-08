/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#pragma once

#include "nanotekspice.hpp"

namespace nts {
    class NanoTekSpice {
        public:
            void run(int argc, const char *argv[]);

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

            std::vector<std::unique_ptr<IComponent *>> _components;

            enum fileState {
                NONE,
                CHIPSETS,
                LINKS
            };

            std::map<std::string, nts::NanoTekSpice::fileState> _states = {
                {".chipsets:", CHIPSETS},
                {".links:", LINKS}
            };
            std::map<fileState, void (NanoTekSpice::*)(std::string &, int)> _handlers = {
                {fileState::NONE, &NanoTekSpice::handleNone},
                {fileState::CHIPSETS, &NanoTekSpice::handleChipset},
                {fileState::LINKS, &NanoTekSpice::handleLink},
            };
            void (NanoTekSpice::*handler)(std::string &, int);

            // std::unordered_map<std::string, void() /*fct generator of component*/>Components;

        };
}
