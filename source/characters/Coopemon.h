/**
 * @file Coopemon.h
 * @author William Fayers (william@fayers.com)
 * @brief Represents a Coopemon character with health and attack attributes.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef COOPEMON_H
#define COOPEMON_H

#include <string>
#include "tui.hpp"
#include <vector>
#include "Move.h"

/**
 * @class Coopemon
 * @brief Represents a Coopemon character with health and attack attributes.
 */
class Coopemon
{
public:
	/**
	 * @brief Constructs a Coopemon with the given name, health, and attack.
	 *
	 * @param controlled Whether the Coopemon is controlled by the player.
	 * @param name The name of the Coopemon.
	 * @param health The initial health points of the Coopemon.
	 * @param moves The moves available to the Coopemon.
	 */
	Coopemon(bool controlled, const std::string &name, int health, const std::vector<Move> &moves);

	/**
	 * @brief Gets whether the Coopemon is controlled by the player.
	 *
	 * @return True if the Coopemon is controlled by the player, false otherwise.
	 */
	bool is_controlled() const;

	/**
	 * @brief Sets whether the Coopemon is controlled by the player.
	 *
	 * @param controlled True if the Coopemon is controlled by the player, false otherwise.
	 */
	void set_controlled(bool controlled);

	/**
	 * @brief Gets the name of the Coopemon.
	 *
	 * @return The name of the Coopemon.
	 */
	std::string get_name() const;

	/**
	 * @brief Gets the current health of the Coopemon.
	 *
	 * @return The current health points of the Coopemon.
	 */
	int get_health() const;

	/**
	 * @brief Displays the health status of the Coopemon.
	 *
	 * @param window
	 * @param y_position
	 */
	void display_health_status(tui::Window &window, int y_position) const;

	/**
	 * @brief Gets the moves available to the Coopemon.
	 *
	 * @return The moves available to the Coopemon.
	 */
	std::vector<Move> get_moves() const;

	/**
	 * @brief Displays the moves available to the Coopemon.
	 *
	 * @param window
	 * @param y_position
	 * @return Move
	 */
	Move display_moves(tui::Window &window, int y_position) const;

	/**
	 * @brief Reduces the health of the Coopemon by the specified damage.
	 *
	 * @param damage The amount of damage to inflict on the Coopemon.
	 */
	void take_damage(int damage);

	/**
	 * @brief Checks if the Coopemon has fainted.
	 *
	 * @return True if the Coopemon's health is 0 or less, false otherwise.
	 */
	bool is_fainted() const;

	/**
	 * @brief Displays the faint message for a Coopemon.
	 *
	 * @param window
	 * @param y_position
	 */
	void display_faint_message(tui::Window &window, int y_position) const;

private:
	std::string name;		 ///< The name of the Coopemon.
	bool controlled;		 ///< Whether the Coopemon is controlled by the player.
	int health;				 ///< The health points of the Coopemon.
	std::vector<Move> moves; ///< The moves available to the Coopemon.
};

#endif // COOPEMON_H