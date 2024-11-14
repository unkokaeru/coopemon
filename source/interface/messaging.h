/**
 * @file messaging.h
 * @author William Fayers (william@fayers.com)
 * @brief Header file for the Coopemon messaging system.
 * @version 0.1.0
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MESSAGING_H
#define MESSAGING_H

#include <string>
#include "tui.hpp"

/**
 * @brief Displays a message on the screen.
 *
 * @param window
 * @param message
 * @param y_position
 * @param colour
 * @param border
 */
void display_message(tui::Window &window,
                     const std::string &message, int y_position, tui::Color colour, bool border);

/**
 * @brief Sleeps for a given number of milliseconds.
 *
 * @param milliseconds
 */
void sleep_for(int milliseconds);

#endif // MESSAGING_H