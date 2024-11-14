/**
 * @file Move.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Represents a move that a Coopemon can perform.
 * @version 0.1.0
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Move.h"
#include <string>

/**
 * @brief Constructs a Move with the given name and power.
 *
 * @param name The name of the move.
 * @param power The power of the move.
 */
Move::Move(const std::string &name, int power)
    : name(name), power(power) {}

/**
 * @brief Gets the name of the move.
 *
 * @return The name of the move.
 */
std::string Move::get_name() const
{
    return name;
}

/**
 * @brief Gets the power of the move.
 *
 * @return The power of the move.
 */
int Move::get_power() const
{
    return power;
}