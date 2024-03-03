/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** TriInputElementary
*/

#pragma once

#include "../AComponent.hpp"
#include "../ElementatyComponents/AElementaryComponent.hpp"

template <typename T>
class TriInputElementary : public nts::AComponent {
    static_assert(std::is_base_of<AElementaryComponent, T>::value, "T must inherit from AElementaryComponent");
    public:
        TriInputElementary(std::string name) : AComponent(name)
        {
            _subComponents = {
                {"T1", std::make_shared<T>("T1")},
                {"T2", std::make_shared<T>("T2")}
            };
            _pins = {
                {1, CREATE_INPUT},
                {2, CREATE_INPUT},
                {3, CREATE_INPUT},
                {4, CREATE_OUTPUT}
            };
        }
        void linkSubComponents() override {
            _subComponents["T1"]->setLink(3, _subComponents["T2"], 1);

            _subComponents["T1"]->getPin(1)->setLink(_pins[1]);
            _subComponents["T1"]->getPin(2)->setLink(_pins[2]);
            _subComponents["T2"]->getPin(2)->setLink(_pins[3]);
            _pins[4]->setLink(_subComponents["T2"]->getPin(3));
        }

    protected:
    private:
        // std::map<std::string, std::shared_ptr<IComponent>> _subComponents;
        // std::vector<std::shared_ptr<nts::Pin>> _pins;
};
