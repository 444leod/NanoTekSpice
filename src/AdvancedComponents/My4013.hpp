/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** My4013
*/

#pragma once

#include "../AComponent.hpp"

/**
 * @brief My4013 class
 * @details The 4013 is a dual D-type flip-flop
 * It is used to store state, each flip-flop has a data, set, reset, clock, q and qb pin
*/
class My4013 : public nts::AComponent {
    public:
        My4013(std::string name);
        void subSimulate(std::string currentName) override;

    protected:
    private:
        std::vector<std::shared_ptr<nts::Pin>> _datas;
        std::vector<std::shared_ptr<nts::Pin>> _sets;
        std::vector<std::shared_ptr<nts::Pin>> _resets;
        std::vector<std::shared_ptr<nts::Pin>> _clocks;
        std::vector<std::shared_ptr<nts::Pin>> _q;
        std::vector<std::shared_ptr<nts::Pin>> _qb;
        std::vector<nts::Tristate> _lastState = {nts::Tristate::Undefined, nts::Tristate::Undefined};
};
