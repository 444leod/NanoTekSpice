/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** IComponentFactory
*/

#pragma once

#include "nanotekspice.hpp"
#include "./IComponent.hpp"
#include "./Parser.hpp"

#include "./SpecialComponents/Input.hpp"
#include "./SpecialComponents/Output.hpp"
#include "./SpecialComponents/Clock.hpp"
#include "./SpecialComponents/True.hpp"
#include "./SpecialComponents/False.hpp"
#include "./ElementatyComponents/And.hpp"
#include "./ElementatyComponents/Or.hpp"
#include "./ElementatyComponents/Xor.hpp"
#include "./ElementatyComponents/Not.hpp"
#include "./GatesComponents/My4001.hpp"
#include "./GatesComponents/My4011.hpp"
#include "./GatesComponents/My4030.hpp"
#include "./GatesComponents/My4069.hpp"
#include "./GatesComponents/My4071.hpp"
#include "./GatesComponents/My4081.hpp"
#include "./AdvancedComponents/Logger.hpp"
#include "./AdvancedComponents/My4008.hpp"
#include "./AdvancedComponents/My4013.hpp"
#include "./AdvancedComponents/My4040.hpp"
#include "./AdvancedComponents/My4512.hpp"
#include "./AdvancedComponents/My4017.hpp"
#include "./BonusComponents/Xnor.hpp"
#include "./BonusComponents/GatedDLatch.hpp"
#include "./BonusComponents/Nand.hpp"
#include "./BonusComponents/Nor.hpp"
#include "./BonusComponents/SRLatch.hpp"
#include "./BonusComponents/GatedSRLatch.hpp"
#include "./BonusComponents/DFlipFlop.hpp"

namespace nts {
    /**
     * @brief IComponentFactory class
     * @details This class is used to create components
    */
    class IComponentFactory {
        public:
            std::shared_ptr<IComponent> createComponent(
                const std::string &componentType,
                const std::string &name,
                std::vector<std::shared_ptr<nts::IComponent>> &inputs,
                std::vector<std::shared_ptr<nts::IComponent>> &outputs,
                std::vector<std::shared_ptr<nts::IComponent>> &clocks,
                std::vector<std::shared_ptr<nts::IComponent>> &loggers);
        private:
            std::map<std::string, std::function<std::shared_ptr<IComponent>(std::string)>> _componentFactory = {
                {"input",   [](std::string name) { return std::make_shared<Input>(name); }},
                {"output",  [](std::string name) { return std::make_shared<Output>(name); }},
                {"clock",   [](std::string name) { return std::make_shared<Clock>(name); }},
                {"true",    [](std::string name) { return std::make_shared<nts::components::True>(name); }},
                {"false",   [](std::string name) { return std::make_shared<nts::components::False>(name); }},
                {"and",     [](std::string name) { return std::make_shared<And>(name); }},
                {"or",      [](std::string name) { return std::make_shared<Or>(name); }},
                {"xor",     [](std::string name) { return std::make_shared<Xor>(name); }},
                {"not",     [](std::string name) { return std::make_shared<Not>(name); }},
                {"4001",    [](std::string name) { return std::make_shared<My4001>(name); }},
                {"4011",    [](std::string name) { return std::make_shared<My4011>(name); }},
                {"4030",    [](std::string name) { return std::make_shared<My4030>(name); }},
                {"4069",    [](std::string name) { return std::make_shared<My4069>(name); }},
                {"4071",    [](std::string name) { return std::make_shared<My4071>(name); }},
                {"4081",    [](std::string name) { return std::make_shared<My4081>(name); }},
                {"logger",  [](std::string name) { return std::make_shared<Logger>(name); }},
                {"4008",    [](std::string name) { return std::make_shared<My4008>(name); }},
                {"4017",    [](std::string name) { return std::make_shared<My4017>(name); }},
                {"4512", [](std::string name) { return std::make_shared<My4512>(name); }},
                {"4013", [](std::string name) { return std::make_shared<My4013>(name); }},
                {"4040", [](std::string name) { return std::make_shared<My4040>(name); }},
                {"xnor", [](std::string name) { return std::make_shared<Xnor>(name); }},
                {"gateddlatch", [](std::string name) { return std::make_shared<GatedDLatch>(name); }},
                {"nand", [](std::string name) { return std::make_shared<Nand>(name); }},
                {"nor", [](std::string name) { return std::make_shared<Nor>(name); }},
                {"srlatch", [](std::string name) { return std::make_shared<SRLatch>(name); }},
                {"gatedsrlatch", [](std::string name) { return std::make_shared<GatedSRLatch>(name); }},
                {"dflipflop", [](std::string name) { return std::make_shared<DFlipFlop>(name); }}
            };
    };
}
