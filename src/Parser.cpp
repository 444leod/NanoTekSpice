/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Parser
*/

#include "Parser.hpp"

/**
 * @brief Parse the arguments
 * @details This function parse the arguments and check if the file is valid
 * It also check if the file extension is valid
 * If the file is not valid, it throws an exception
 * If the file is valid, it calls the parseFile function
 * If the parameter is -h, it prints the help message
 *
 * @param argc - number of arguments
 * @param argv - arguments
 *
 * @throws ParsingError - if the file is not valid
 * @throws HelpFlag - if the parameter is -h
*/
void nts::Parser::parseArgs(int argc, const char *argv[])
{
    if (argc != 2)
        throw nts::Parser::ParsingError("Invalid number of arguments");
    if (std::string(argv[1]) == "-h") {
        std::cout << "USAGE" << std::endl;
        std::cout << "\t./nanotekspice [filename].nts" << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\tfilename.nts: file describing the circuit" << std::endl;
        throw nts::Parser::HelpFlag();
    }
    std::string s = argv[1];
    if (s.ends_with(".nts") == false)
        throw nts::Parser::ParsingError("Invalid file extension");

    parseFile(argv[1]);
    if (_chipsets.empty())
        throw nts::Parser::ParsingError("No chipset found");
}

/**
 * @brief Parse the file
 * @details This function parse the file and call the right handler for each line
 * It also check if the file is valid
 * If the file is not valid, it throws an exception
 * If the file is valid, it calls the right handler for each line
 *
 * @param filename - the file to parse
 *
 * @throws ParsingError - if the file is not valid
*/
void nts::Parser::parseFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw nts::Parser::ParsingError("File is not valid");

    std::string line;
    nts::Parser::fileState state = NONE;
    int lineCount = 0;

    while (std::getline(file, line)) {
        lineCount++;
        line = line.substr(0, line.find('#'));
        if (line.empty())
            continue;
        if (_states.contains(line)) {
            for (auto &fileState : _fileStates) {
                if (fileState == _states[line])
                    throw nts::Parser::ParsingError("Invalid line: line " + std::to_string(lineCount));
            }
            _fileStates.push_back(_states[line]);
            state = _states[line];
            continue;
        }

        _handlers[state](line, lineCount);
    }

    file.close();
}

/**
 * @brief Handle the chipset line
 * @details This function handle the chipset line
 * It split the line and call the right function to handle the chipset
 *
 * @param chipset - the chipset line
 * @param lineCount - the line number
 *
 * @throws ParsingError - if the line is not valid
*/
void nts::Parser::handleChipset(std::string &chipset, int lineCount)
{
    std::stringstream ss(chipset);
    std::string token = "";
    std::vector<std::string> tokens = {};
    while (ss >> token)
        tokens.push_back(token);
    if (tokens.size() != 2)
        throw nts::Parser::ParsingError("Invalid line: line " + std::to_string(lineCount));

    for (auto &component : _components) {
        if (component->getName() == tokens[1])
            throw nts::Parser::ParsingError("Component already exists: " + tokens[1]);
    }
    _chipsets.push_back({tokens[0], tokens[1]});
}

/**
 * @brief Handle the link line
 * @details This function handle the link line
 * It split the line and call the right function to handle the link
 *
 * @param link - the link line
 * @param lineCount - the line number
 *
 * @throws ParsingError - if the line is not valid
*/
void nts::Parser::handleLink(std::string &link, int lineCount)
{
    std::stringstream ss(link);
    std::string token;
    std::vector<std::string> tokens;
    while (ss >> token)
        tokens.push_back(token);
    if (tokens.size() != 2)
        throw nts::Parser::ParsingError("Invalid line: line " + std::to_string(lineCount));

    _links.push_back({tokens[0], tokens[1]});
}

/**
 * @brief Handle the none line
 * @details This function handle the none line
 * (Skip the line)
 *
 * @param line - the none line
 * @param lineCount - the line number
*/
void nts::Parser::handleNone(std::string &line, int lineCount)
{
    (void)line;
    throw nts::Parser::ParsingError("Invalid line: line " + std::to_string(lineCount));
}

/**
 * @brief Get the links
 * @details This function return the links
 *
 * @return the links
*/
std::vector<std::pair<std::string, std::string>> nts::Parser::getLinks() const
{
    return _links;
}

/**
 * @brief Get the chipsets
 * @details This function return the chipsets
 *
 * @return the chipsets
*/
std::vector<std::pair<std::string, std::string>> nts::Parser::getChipsets() const
{
    return _chipsets;
}
