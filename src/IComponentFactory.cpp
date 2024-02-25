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

    if (componentType == "input") {
        component = std::make_unique<Input>(name);
        inputs.push_back(component);
    } else if (componentType == "output") {
        component = std::make_unique<Output>(name);
        outputs.push_back(component);
    } else if (componentType == "clock") {
        component = std::make_unique<Clock>(name);
        clocks.push_back(component);
    } else {
        if (_componentFactory.find(componentType) == _componentFactory.end())
            throw nts::Parser::ParsingError("Invalid component type: " + componentType);
        component = _componentFactory[componentType](name);
    }

    return component;
}
