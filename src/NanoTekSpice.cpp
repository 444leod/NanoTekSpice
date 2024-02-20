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
    try {
        this->parseArgs(argc, argv);
        return this->shell();
    } catch (const nts::NanoTekSpice::ParsingError &e) {
        std::cerr << "Something went wrong with arguments: " << std::endl;
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (const nts::NanoTekSpice::HelpFlag &e) {
        return 0;
    }
    return 0;
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
    std::string s = argv[1];
    if (s.ends_with(".nts") == false)
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
void nts::NanoTekSpice::handleChipset(std::string &chipset, int lineCount)
{
    std::stringstream ss(chipset);
    std::string token = "";
    std::vector<std::string> tokens = {};
    while (ss >> token)
        tokens.push_back(token);
    if (tokens.size() != 2)
        throw nts::NanoTekSpice::ParsingError("Invalid line: line " + std::to_string(lineCount));

    for (auto &component : _components) {
        if (component->getName() == tokens[1])
            throw nts::NanoTekSpice::ParsingError("Component already exists: " + tokens[1]);
    }
    this->IComponentFactory(tokens[0], tokens[1]);
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
void nts::NanoTekSpice::handleNone(std::string &line, int lineCount)
{
    (void)line;
    (void)lineCount;
}

int nts::NanoTekSpice::shell()
{
    std::string input;
    std::stringstream ss("");

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
            throw nts::NanoTekSpice::ParsingError("Invalid link: " + link.first + " " + link.second);
        component1->setLink(pin1, component2, pin2);
    }

    // input1->setLink(1, output1, 1);
    // input2->setLink(1, output2, 1);
    // clock1->setLink(1, clock_output, 1);
    // input1->setPinValue(1, nts::Tristate::True);
    // input2->setPinValue(1, nts::Tristate::False);

    while (1) {
        if (isatty(0))
            std::cout << "> ";
        if (!std::getline(std::cin, input))
            break;
        ss << input;
        ss >> input;
        if (_commands.find(input) != _commands.end())
            _commands.at(input)();
        else {
            try {
                assign(input, ss);
            } catch (const nts::NanoTekSpice::ParsingError &e) {
                std::cerr << "Something went wrong with the command: " << std::endl;
                std::cerr << e.what() << std::endl;
            }
        }
    }
    return 0;
}

void nts::NanoTekSpice::exit()
{
    std::exit(0);
}

void nts::NanoTekSpice::display()
{
    nts::Tristate pinValue;

    std::cout << "tick: " << _tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &input : _inputs) {
        pinValue = input->getPinValue(1);
        std::cout << "\t" << input->getName() << "(" << input << "): ";
        if (pinValue == nts::Tristate::Undefined)
            std::cout << "U" << std::endl;
        else
            std::cout << pinValue << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto &output : _outputs) {
        pinValue = output->getPinValue(1);
        std::cout << "\t" << output->getName() << "(" << output << "): ";
        if (pinValue == nts::Tristate::Undefined)
            std::cout << "U" << std::endl;
        else
            std::cout << pinValue << std::endl;
    }
}

void updateComponentValue(std::vector<std::pair<std::string, std::string>> assignements, std::vector<std::shared_ptr<nts::IComponent>> components)
{
    for (auto &assignement : assignements) {
        for (auto &component : components) {
            if (component->getName() == assignement.first) {
                if (!component->isInput())
                    throw nts::NanoTekSpice::ParsingError("Invalid component type: " + assignement.first);
                switch (assignement.second[0]) {
                    case '0':
                        component->setPinValue(1, nts::Tristate::False);
                        break;
                    case '1':
                        component->setPinValue(1, nts::Tristate::True);
                        break;
                    case 'U':
                        component->setPinValue(1, nts::Tristate::Undefined);
                        break;
                    default:
                        break;
                }
            }
        }
        std::cout << "Assigning " << assignement.second << " to " << assignement.first << std::endl;
    }
}

void updateClocks(std::vector<std::shared_ptr<nts::IComponent>> clocks)
{
    for (auto &clock : clocks) {
        if (clock->getPinValue(1) == nts::Tristate::Undefined)
            continue;
        clock->setPinValue(1, clock->getPinValue(1) == nts::Tristate::True ? nts::Tristate::False : nts::Tristate::True);
    }
}

void nts::NanoTekSpice::simulate()
{
    _tick++;
    updateClocks(_clocks);
    updateComponentValue(_assignements, _components);
    _assignements = {};
    for (auto &component : _components) {
        component->simulate();
    }
}

void nts::NanoTekSpice::loop()
{
    while (1) {
        nts::NanoTekSpice::simulate();
        nts::NanoTekSpice::display();
    }
}

void nts::NanoTekSpice::assign(const std::string &input, std::stringstream &ss)
{
    std::string nextWord;
    ss >> nextWord;

    if (nextWord != "")
        throw nts::NanoTekSpice::ParsingError("Invalid command");

    if (input.find('=') == std::string::npos)
        throw nts::NanoTekSpice::ParsingError("Invalid command");

    std::string left = input.substr(0, input.find('='));
    std::string right = input.substr(input.find('=') + 1);

    if (left.empty() || right.empty())
        throw nts::NanoTekSpice::ParsingError("Invalid command");
    if (right != "0" && right != "1" && right != "U")
        throw nts::NanoTekSpice::ParsingError("Invalid component value: " + right);
    for (auto &component : _components) {
        if (component->getName() == left) {
            _assignements.push_back({left, right});
            std::cout << "Assigning..." << std::endl;
            return;
        }
    }
    throw nts::NanoTekSpice::ParsingError("Invalid component name: " + left);
}


std::shared_ptr<nts::IComponent> nts::NanoTekSpice::IComponentFactory(std::string componentType, std::string name)
{
    std::shared_ptr<nts::IComponent> component;

    if (componentType == "input") {
        component = std::make_unique<Input>(name);
        _inputs.push_back(component);
    } else if (componentType == "output") {
        component = std::make_unique<Output>(name);
        _outputs.push_back(component);
    } else if (componentType == "clock") {
        component = std::make_unique<Clock>(name);
        _clocks.push_back(component);
    } else {
        if (_componentFactory.find(componentType) == _componentFactory.end())
            throw nts::NanoTekSpice::ParsingError("Invalid component type: " + componentType);
        component = _componentFactory[componentType](name);
    }
    _components.push_back(component);

    return component;
}
