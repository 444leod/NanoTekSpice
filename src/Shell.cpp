/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Shell
*/

#include "Shell.hpp"

nts::Shell::Shell(
    std::vector<std::shared_ptr<nts::IComponent>> components,
    std::vector<std::shared_ptr<nts::IComponent>> inputs,
    std::vector<std::shared_ptr<nts::IComponent>> outputs,
    std::vector<std::shared_ptr<nts::IComponent>> clocks,
    std::vector<std::shared_ptr<nts::IComponent>> loggers
){
    _components = components;
    _inputs = inputs;
    _outputs = outputs;
    _clocks = clocks;
    _loggers = loggers;
}

/**
 * @brief Run the shell
 * @details This function is used to run the shell and handles the commands
 * @return 0
*/
int nts::Shell::run()
{
    std::string input;
    std::stringstream ss("");

    for (auto &component : _components) {
        component->linkSubComponents();
    }
    while (1) {
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
            } catch (const nts::Shell::ParsingError &e) {
                std::cerr << "Something went wrong with the command: " << std::endl;
                std::cerr << e.what() << std::endl;
            }
        }
    }
    return 0;
}

/**
 * @brief Exit the shell
*/
void nts::Shell::exit()
{
    std::exit(0);
}

/**
 * @brief Display the components
 * @details This function display the components and their values
*/
void nts::Shell::display()
{
    nts::Tristate pinValue;

    std::cout << "tick: " << nts::currentTick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &component : _components) {
        if (!component->isInput())
            continue;
        pinValue = component->getPinValue(1);
        std::cout << "  " << component->getName() << ": " << _statesToString[pinValue] << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto &output : _outputs) {
        pinValue = output->getPinValue(1);
        std::cout << "  " << output->getName() << ": " << _statesToString[pinValue] << std::endl;
    }
}

/**
 * @brief Update the component value
 * @throws ParsingError - if the component type is invalid
*/
void updateComponentValue(
    std::vector<std::pair<std::string, std::string>> assignements,
    std::vector<std::shared_ptr<nts::IComponent>> components
){
    for (auto &assignement : assignements) {
        for (auto &component : components) {
            if (component->getName() == assignement.first) {
                if (!component->isInput())
                    throw nts::Shell::ParsingError("Invalid component type: " + assignement.first);
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
    }
}

/**
 * @brief Update the clocks
*/
void updateClocks(std::vector<std::shared_ptr<nts::IComponent>> clocks)
{
    for (auto &clock : clocks) {
        if (clock->getPinValue(1) == nts::Tristate::Undefined)
            continue;
        clock->setPinValue(1, clock->getPinValue(1) == nts::Tristate::True ? nts::Tristate::False : nts::Tristate::True);
    }
}

/**
 * @brief Simulate the components
 * @details First update the clocks and then the component value
 * @throws ParsingError - if the command is invalid
*/
void nts::Shell::simulate()
{
    nts::currentTick++;
    updateClocks(_clocks);
    updateComponentValue(_assignements, _components);
    _assignements.clear();
    for (auto &output : _outputs) {
        output->simulate(output->getName());
    }
    for (auto &logger : _loggers) {
        logger->simulate(logger->getName());
    }
    for (auto &component : _components) {
        component->dump();
    }
}

bool running = true;

/**
 * @brief Loop the simulation
 * @details Does simulate and display in a loop until the user presses Ctrl+C
 * @throws ParsingError - if the command is invalid
*/
void nts::Shell::loop()
{
    running = true;
    signal(SIGINT, [](int sig) { (void)sig; running = false; });

    while (running) {
        nts::Shell::simulate();
        nts::Shell::display();
    }
    signal(SIGINT, SIG_DFL);
}

/**
 * @brief Assign a value to a component
 * @throws ParsingError - if the command is invalid
*/
void nts::Shell::assign(const std::string &input, std::stringstream &ss)
{
    std::string nextWord;
    ss >> nextWord;

    if (nextWord != "")
        throw nts::Shell::ParsingError("Invalid command");

    if (input.find('=') == std::string::npos)
        throw nts::Shell::ParsingError("Invalid command");

    std::string left = input.substr(0, input.find('='));
    std::string right = input.substr(input.find('=') + 1);

    if (left.empty() || right.empty())
        throw nts::Shell::ParsingError("Invalid command");
    if (right != "0" && right != "1" && right != "U")
        throw nts::Shell::ParsingError("Invalid component value: " + right);
    for (auto &component : _components) {
        if (component->getName() == left) {
            _assignements.push_back({left, right});
            return;
        }
    }
    throw nts::Shell::ParsingError("Invalid component name: " + left);
}

void nts::Shell::sd()
{
    nts::Shell::simulate();
    nts::Shell::display();
}
