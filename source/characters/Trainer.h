/**
 * @file Trainer.h
 * @author William Fayers (william@fayers.com)
 * @brief Represents a Trainer who can manage a collection of Coopemons.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>
#include "Coopemon.h"

/**
 * @class Trainer
 * @brief Represents a Trainer who can manage a collection of Coopemons.
 */
class Trainer
{
public:
    /**
     * @brief Constructs a Trainer with the given name.
     * @param name The name of the Trainer.
     */
    Trainer(const std::string &name);

    /**
     * @brief Gets the name of the Trainer.
     * @return The name of the Trainer.
     */
    std::string get_name() const;

    /**
     * @brief Adds a Coopemon to the Trainer's collection.
     * @param coopemon The Coopemon to be added.
     */
    void add_coopemon(Coopemon &coopemon);

    /**
     * @brief Retrieves a random Coopemon from the Trainer's collection.
     * @return A constant reference to a randomly selected Coopemon.
     */
    const Coopemon &get_random_coopemon() const;

private:
    std::string name;                ///< The name of the Trainer.
    std::vector<Coopemon> coopemons; ///< A collection of Coopemons owned by the Trainer.
};

#endif // TRAINER_H