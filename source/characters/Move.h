/**
 * @file Move.h
 * @author William Fayers (william@fayers.com)
 * @brief Represents a move that a Coopemon can perform.
 * @version 0.1.0
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MOVE_H
#define MOVE_H

#include <string>

/**
 * @class Move
 * @brief Represents a move that a Coopemon can perform.
 */
class Move
{
public:
    /**
     * @brief Constructs a Move with the given name and power.
     *
     * @param name The name of the move.
     * @param power The power of the move.
     */
    Move(const std::string &name, int power);

    /**
     * @brief Gets the name of the move.
     *
     * @return The name of the move.
     */
    std::string get_name() const;

    /**
     * @brief Gets the power of the move.
     *
     * @return The power of the move.
     */
    int get_power() const;

private:
    std::string name; ///< The name of the move
    int power;        ///< The power of the move
};

#endif // MOVE_H