/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponentFactory
*/

#include "IComponentFactory.hpp"

using nts::IComponent;
using nts::IComponentFactory;

std::shared_ptr<IComponent> IComponentFactory::createComponent(
                const std::string &componentType,
                const std::string &name,
                std::vector<std::shared_ptr<nts::IComponent>> &inputs,
                std::vector<std::shared_ptr<nts::IComponent>> &outputs,
                std::vector<std::shared_ptr<nts::IComponent>> &clocks)
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

    return component;
}