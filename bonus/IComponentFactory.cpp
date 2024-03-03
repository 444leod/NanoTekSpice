/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponentFactory
*/

#include "IComponentFactory.hpp"

using nts::IComponent;
using nts::IComponentFactory;

/**
 * @brief Creates a component
 * @details Handle input, output and clock components
 * @throws ParsingError if the component type is invalid
 * @param componentType - the type of the component
 * @param name - the name of the component 
 * @param inputs - the inputs of the component
 * @param outputs - the outputs of the component
 * @param clocks - the clocks of the component
 * @return std::shared_ptr<IComponent> - the created component
*/
std::shared_ptr<IComponent> IComponentFactory::createComponent(
    const std::string &componentType,
    const std::string &name,
    std::vector<std::shared_ptr<nts::IComponent>> &inputs,
    std::vector<std::shared_ptr<nts::IComponent>> &outputs,
    std::vector<std::shared_ptr<nts::IComponent>> &clocks,
    std::vector<std::shared_ptr<nts::IComponent>> &loggers)
{
    std::shared_ptr<nts::IComponent> component;

    if (_componentFactory.find(componentType) == _componentFactory.end())
        throw nts::Parser::ParsingError("Invalid component type: " + componentType);
    component = _componentFactory[componentType](name);

    if (componentType == "input")
        inputs.push_back(component);
    else if (componentType == "output")
        outputs.push_back(component);
    else if (componentType == "clock")
        clocks.push_back(component);
    else if (componentType == "logger")
        loggers.push_back(component);

    return component;
}
