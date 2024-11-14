/**
 * @file menu.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Implementation of the Coopemon menus.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "menu.h"

/**
 * @brief Constructor for CoopemonMenu.
 *
 * @param window The TUI window for rendering.
 */
CoopemonMenu::CoopemonMenu(tui::Window &window) : window(window) {}

/**
 * @brief Renders a list of paragraphs in the window.
 *
 * @param y_position The y position to display the message.
 * @param paragraphs The paragraphs representing the options.
 * @param highlight The index of the currently highlighted option.
 */
void CoopemonMenu::render_list(int y_position, const std::vector<tui::Paragraph> &paragraphs,
                               int highlight)
{
    for (size_t index = 0; index < paragraphs.size(); ++index)
    {
        tui::Paragraph paragraph = paragraphs[index];
        if (index == highlight)
        {
            paragraph.text_style.foreground = tui::Color::WHITE;
            paragraph.text_style.background = tui::Color::BLUE;
        }
        else
        {
            paragraph.text_style.foreground = tui::Color::WHITE;
            paragraph.text_style.background = tui::Color::BLACK;
        }
        paragraph.set_dimensions(1, y_position + index, paragraph.text.length() + 2, 3);
        paragraph.border = false;
        window.add(paragraph);
    }
}