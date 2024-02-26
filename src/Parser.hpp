/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Parser
*/

#pragma once

#include "nanotekspice.hpp"
#include "IComponent.hpp"

namespace nts {
    class Parser {
        public:
            Parser() = default;
            ~Parser() = default;
            class ParsingError : public std::exception {
                public:
                    ParsingError(const std::string &message) : _message(message) {}
                    const char *what() const noexcept override { return _message.c_str(); }
                private:
                    std::string _message;
            };
            class HelpFlag : public std::exception {
            };
            void parseArgs(int argc, const char *argv[]);
            std::vector<std::pair<std::string, std::string>> getLinks() const;
            std::vector<std::pair<std::string, std::string>> getChipsets() const;

        private:
            std::vector<std::shared_ptr<nts::IComponent>> _components = {};
            std::vector<std::pair<std::string, std::string>> _links = {};
            std::vector<std::pair<std::string, std::string>> _chipsets = {};

            void parseFile(const std::string &filename);
            enum fileState {
                NONE,
                CHIPSETS,
                LINKS
            };
            void handleChipset(std::string &line, int lineCount);
            void handleLink(std::string &line, int lineCount);
            void handleNone(std::string &line, int lineCount);

            std::map<std::string, nts::Parser::fileState> _states = {
                {".chipsets:", nts::Parser::fileState::CHIPSETS},
                {".links:", nts::Parser::fileState::LINKS}
            };
            std::vector<fileState> _fileStates = {};
            std::map<nts::Parser::fileState, std::function<void(std::string &, int)>> _handlers = {
                {nts::Parser::fileState::NONE,      [&](std::string &chipset, int lineCount) { handleNone(chipset, lineCount); }},
                {nts::Parser::fileState::CHIPSETS,  [&](std::string &chipset, int lineCount) { handleChipset(chipset, lineCount); }},
                {nts::Parser::fileState::LINKS,     [&](std::string &chipset, int lineCount) { handleLink(chipset, lineCount); }}
            };
    };
};
