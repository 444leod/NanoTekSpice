/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4512
*/

#include "My4512.hpp"

My4512::My4512(std::string name) : AComponent(name)
{
    _pins = {
        {1, NULL},//x0
        {2, NULL},
        {3, NULL},
        {4, NULL},
        {5, NULL},
        {6, NULL},
        {7, NULL},//x6
        {8, std::make_shared<nts::Pin>(nts::PinType::INPUT, nts::Tristate::Undefined, false, true)},//VSS
        {9, NULL},//x7
        {10, NULL},//inhibit
        {11, NULL},//adress input A
        {12, NULL},//adress input B
        {13, NULL},//adress input C
        {14, std::make_shared<nts::Pin>(nts::PinType::OUTPUT, nts::Tristate::Undefined)},//Z
        {15, NULL},//OE
        {16, std::make_shared<nts::Pin>(nts::PinType::INPUT, nts::Tristate::Undefined, false, true)}//VDD
    };
}

void My4512::simulate()
{

}
