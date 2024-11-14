/**
 * @file battle.h
 * @author William Fayers (william@fayers.com)
 * @brief Header file for the Coopemon battle system.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BATTLE_H
#define BATTLE_H

#include "tui.hpp"
#include "Coopemon.h"

/**
 * @class Battle
 * @brief Represents a battle between two Coopemon characters.
 */
class Battle
{
public:
    /**
     * @brief Construct a new Battle:: Battle object.
     *
     * @param player
     * @param enemy
     * @param win
     */
    Battle(Coopemon &player, Coopemon &enemy, tui::Window &win);

    /**
     * @brief Perform the battle loop.
     *
     */
    void start();

private:
    Coopemon &playerCoopemon; ///< The player's Coopemon character.
    Coopemon &enemyCoopemon;  ///< The enemy Coopemon character.
    tui::Window &window;      ///< The TUI window for rendering.
    bool quit;                ///< Flag to indicate if the battle should end.

    /**
     * @brief Displays the battle information.
     *
     */
    void display_battle_info();

    /**
     * @brief Performs a turn in the battle.
     *
     * @param attacker
     * @param defender
     * @param dialogue
     * @param colour
     * @param y_position
     * @return int
     */
    int perform_turn(Coopemon &attacker, Coopemon &defender, const std::string &dialogue,
                     tui::Color colour, int y_position);

    /**
     * @brief Displays the result of a battle.
     *
     * @param coopemon
     * @param y_position
     */
    void display_result(const Coopemon &coopemon, int y_position);
};

void battle(Coopemon &playerCoopemon, Coopemon &enemyCoopemon, tui::Window &window);

#endif // BATTLE_H