/**
 * @file Trainer.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Represents a Trainer who can manage a collection of Coopemons.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Trainer.h"
#include <cstdlib>

/**
 * @brief Constructs a Trainer with the given name.
 *
 * @param name The name of the Trainer.
 */
Trainer::Trainer(const std::string &name) : name(name) {}

/**
 * @brief Gets the name of the Trainer.
 *
 * @return The name of the Trainer.
 */
std::string Trainer::get_name() const
{
    return name;
}

/**
 * @brief Adds a Coopemon to the Trainer's collection.
 *
 * @param coopemon The Coopemon to be added.
 */
void Trainer::add_coopemon(Coopemon &coopemon)
{
    coopemon.set_controlled(false);
    coopemons.push_back(coopemon);
}

/**
 * @brief Retrieves a random Coopemon from the Trainer's collection.
 *
 * @return A constant reference to a randomly selected Coopemon.
 */
const Coopemon &Trainer::get_random_coopemon() const
{
    return coopemons[rand() % coopemons.size()];
}