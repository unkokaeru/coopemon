/**
 * @file messaging.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Implementation of the Coopemon messaging system.
 * @version 0.1.0
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "messaging.h"
#include <chrono>
#include <string>
#include <thread>
#include "tui.hpp"

/**
 * @brief Display a message in the TUI window.
 *
 * @param window
 * @param message
 * @param y_position
 * @param colour
 * @param border
 */
void display_message(tui::Window &window,
                     const std::string &message, int y_position, tui::Color colour, bool border)
{
    tui::Paragraph message_paragraph;
    message_paragraph.text = message;
    message_paragraph.set_dimensions(1, y_position, message_paragraph.text.length() + 2, 3);
    message_paragraph.text_style.foreground = colour;
    message_paragraph.border = border;
    window.add(message_paragraph);
}

/**
 * @brief Sleeps for a given number of milliseconds.
 *
 * @param milliseconds
 */
void sleep_for(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}