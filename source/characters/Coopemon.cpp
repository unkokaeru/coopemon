/**
 * @file Coopemon.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Represents a Coopemon character with health and attack attributes.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 */

#include "Coopemon.h"
#include "tui.hpp"
#include <string>
#include <vector>
#include "Dialogue.h"
#include "messaging.h"
#include "menu.h"
#include "Move.h"

/**
 * @brief Constructs a Coopemon with the given name, health, and attack.
 *
 * @param controlled Whether the Coopemon is controlled by the player.
 * @param name The name of the Coopemon.
 * @param health The initial health points of the Coopemon.
 * @param moves The moves available to the Coopemon.
 */
Coopemon::Coopemon(bool controlled, const std::string &name, int health,
                   const std::vector<Move> &moves)
    : controlled(controlled), name(name), health(health), moves(moves) {}

/**
 * @brief Gets whether the Coopemon is controlled by the player.
 *
 * @return True if the Coopemon is controlled by the player, false otherwise.
 */
bool Coopemon::is_controlled() const
{
    return controlled;
}

/**
 * @brief Sets whether the Coopemon is controlled by the player.
 *
 * @param controlled True if the Coopemon is controlled by the player, false otherwise.
 */
void Coopemon::set_controlled(bool controlled)
{
    this->controlled = controlled;
}

/**
 * @brief Gets the name of the Coopemon.
 *
 * @return The name of the Coopemon.
 */
std::string Coopemon::get_name() const
{
    return name;
}

/**
 * @brief Gets the current health of the Coopemon.
 *
 * @return The current health points of the Coopemon.
 */
int Coopemon::get_health() const
{
    return health;
}

/**
 * @brief Displays the health status of the Coopemon.
 *
 * @param window
 * @param y_position
 */
void Coopemon::display_health_status(tui::Window &window, int y_position) const
{
    char health_message[100];
    snprintf(health_message, sizeof(health_message), Dialogue::HEALTH_STATUS.c_str(),
             name.c_str(), health);
    display_message(window, health_message, y_position, tui::Color::WHITE, false);
}

/**
 * @brief Gets the moves available to the Coopemon.
 *
 * @return The moves available to the Coopemon.
 */
std::vector<Move> Coopemon::get_moves() const
{
    return moves;
}

/**
 * @brief Displays the moves available to the Coopemon.
 *
 * @param window
 * @param y_position
 * @return Move
 */
Move Coopemon::display_moves(tui::Window &window, int y_position) const
{
    CoopemonMenu menu(window);
    Move selected_move("", 0);
    menu.choose_from_list(y_position, Dialogue::CHOOSE_MOVE, moves,
                          [&](const Move &move)
                          { selected_move = move; });
    return selected_move;
}

/**
 * @brief Reduces the health of the Coopemon by the specified damage.
 *
 * @param damage The amount of damage to inflict on the Coopemon.
 */
void Coopemon::take_damage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0; // Prevent negative health
    }
}

/**
 * @brief Checks if the Coopemon has fainted.
 *
 * @return True if the Coopemon's health is 0 or less, false otherwise.
 */
bool Coopemon::is_fainted() const
{
    return health <= 0;
}

/**
 * @brief Displays the faint message for a Coopemon.
 *
 * @param window
 * @param y_position
 */
void Coopemon::display_faint_message(tui::Window &window, int y_position) const
{
    char faint_message[100];
    snprintf(faint_message, sizeof(faint_message), Dialogue::FAINT_MESSAGE.c_str(),
             name.c_str());
    display_message(window, faint_message, y_position, tui::Color::WHITE, false);
}