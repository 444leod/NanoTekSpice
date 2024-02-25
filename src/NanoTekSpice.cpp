/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#include "NanoTekSpice.hpp"
#include "./SpecialComponents/Input.hpp"
#include "./SpecialComponents/Output.hpp"

/**
 * @brief main NanoTekSpice run function
 * @details This function is the main entry point of the program
 * It runs the parsing of the arguments and the file and run the program
 * It catch the exceptions and print the error message
 *
 * @param argc - number of arguments
 * @param argv - arguments
*/
int nts::NanoTekSpice::run(int argc, const char *argv[])
{
    std::unique_ptr<nts::Parser> parser;
    try {
        parser->parseArgs(argc, argv);
        _links = parser->getLinks();
        _chipsets = parser->getChipsets();
        this->bindChipsets();
        std::unique_ptr<nts::Shell> shell = std::make_unique<nts::Shell>(_components, _inputs, _outputs, _clocks);
        return shell->run();
    } catch (const nts::Parser::ParsingError &e) {
        std::cerr << "Parsing error: " << std::endl;
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (const nts::Parser::HelpFlag &e) {
        return 0;
    } catch (const nts::Shell::ParsingError &e) {
        std::cerr << "Shell error: " << std::endl;
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (const std::exception &e) {
        std::cerr << "Unknown error: " << std::endl;
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

void nts::NanoTekSpice::bindChipsets()
{
    std::unique_ptr<nts::IComponentFactory> factory = std::make_unique<nts::IComponentFactory>();
    for (auto &chipset : _chipsets) {
        _components.push_back(factory->createComponent(chipset.first, chipset.second, _inputs, _outputs, _clocks));
    }
    for (auto &link : _links) {
        std::shared_ptr<IComponent> component1;
        std::shared_ptr<IComponent> component2;
        std::string name1 = link.first.substr(0, link.first.find(':'));
        std::string name2 = link.second.substr(0, link.second.find(':'));

        int pin1 = std::stoi(link.first.substr(link.first.find(':') + 1));
        int pin2 = std::stoi(link.second.substr(link.second.find(':') + 1));

        for (auto &component : _components) {
            if (component->getName() == name1)
                component1 = component;
            if (component->getName() == name2)
                component2 = component;
        }
        if (component1 == nullptr || component2 == nullptr)
            throw nts::Parser::ParsingError("Invalid link: " + link.first + " " + link.second);
        component1->setLink(pin1, component2, pin2);
    }
}
