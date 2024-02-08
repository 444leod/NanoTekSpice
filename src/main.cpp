/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** main.cpp
*/

#include "NanoTekSpice.hpp"

/**
 * @brief Main function
 * @details This function is the main entry point of the program
 *
 * @param argc - number of arguments
 * @param argv - arguments
 *
 * @return 0
*/
int main(int argc, const char *argv[]) {
    nts::NanoTekSpice nts;

    nts.run(argc, argv);
    return 0;
}
