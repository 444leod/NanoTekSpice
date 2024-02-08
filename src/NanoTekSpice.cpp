/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#include "NanoTekSpice.hpp"

#include <string.h>

/**
 * @brief main NanoTekSpice run function
 * @details This function is the main entry point of the program
 * It runs the parsing of the arguments and the file and run the program
 * It catch the exceptions and print the error message
 *
 * @param argc - number of arguments
 * @param argv - arguments
*/
void nts::NanoTekSpice::run(int argc, const char *argv[])
{
    try {
        this->parseArgs(argc, argv);
    } catch (const nts::NanoTekSpice::ParsingError &e) {
        std::cerr << "Something went wrong with arguments: " << std::endl;
        std::cerr << e.what() << std::endl;
        exit(84);
    } catch (const nts::NanoTekSpice::HelpFlag &e) {
        exit(0);
    }
    exit(0);
}

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
void nts::NanoTekSpice::parseArgs(int argc, const char *argv[])
{
    if (argc != 2)
        throw nts::NanoTekSpice::ParsingError("Invalid number of arguments");
    if (std::string(argv[1]) == "-h") {
        std::cout << "USAGE" << std::endl;
        std::cout << "\t./nanotekspice [filename].nts" << std::endl;
        std::cout << "DESCRIPTION" << std::endl;
        std::cout << "\tfilename.nts: file describing the circuit" << std::endl;
        throw nts::NanoTekSpice::HelpFlag();
    }
    const char *extension = strstr(argv[1], ".nts");
    if (extension == NULL || std::string(extension) != ".nts")
        throw nts::NanoTekSpice::ParsingError("Invalid file extension");

    this->parseFile(argv[1]);
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
void nts::NanoTekSpice::parseFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw nts::NanoTekSpice::ParsingError("File is not valid");

    std::string line;
    nts::NanoTekSpice::fileState state = NONE;
    int lineCount = 0;

    while (std::getline(file, line)) {
        lineCount++;
        if (line[0] == '#' || line.empty())
            continue;

        if (_states.find(line) != _states.end()) {
            state = _states[line];
            continue;
        }

        this->handler = _handlers[state];
        (this->*handler)(line, lineCount);
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
void nts::NanoTekSpice::handleChipset(std::string &chipset, int lineCount)
{
    std::stringstream ss(chipset);
    std::string token;
    std::vector<std::string> tokens;
    while (ss >> token)
        tokens.push_back(token);
    if (tokens.size() != 2)
        throw nts::NanoTekSpice::ParsingError("Invalid line: line " + std::to_string(lineCount));

    //handle chipset here
    // std::cout << "Chipset: " << tokens[0] << " " << tokens[1] << std::endl;
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
void nts::NanoTekSpice::handleLink(std::string &link, int lineCount)
{
    std::stringstream ss(link);
    std::string token;
    std::vector<std::string> tokens;
    while (ss >> token)
        tokens.push_back(token);
    if (tokens.size() != 2)
        throw nts::NanoTekSpice::ParsingError("Invalid line: line " + std::to_string(lineCount));

    //handle link here
    // std::cout << "Link: " << tokens[0] << " " << tokens[1] << std::endl;
}

/**
 * @brief Handle the none line
 * @details This function handle the none line
 * (Skip the line)
 *
 * @param line - the none line
 * @param lineCount - the line number
*/
void nts::NanoTekSpice::handleNone(std::string &line, int lineCount)
{
    (void)line;
    (void)lineCount;
}
