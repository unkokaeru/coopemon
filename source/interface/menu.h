/**
 * @file menu.h
 * @author William Fayers (william@fayers.com)
 * @brief Header file for the Coopemon menus.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <functional>
#include <string>
#include "tui.hpp"
#include "Coopemon.h"
#include "Dialogue.h"
#include "messaging.h"

/**
 * @class CoopemonMenu
 * @brief Represents a menu for selecting Coopemon options.
 */
class CoopemonMenu
{
public:
    /**
     * @brief Constructor for CoopemonMenu.
     *
     * @param window The TUI window for rendering.
     */
    CoopemonMenu(tui::Window &window);

    /**
     * @brief Displays a list of options and allows the user to select one.
     *
     * @tparam T The type of the options.
     * @tparam F The type of the selection handler.
     * @param y_position The y position to display the message.
     * @param message The message to display.
     * @param options The list of options to choose from.
     * @param on_select The selection handler function.
     */
    template <typename T, typename F>
    void choose_from_list(int y_position, std::string message,
                          const std::vector<T> &options, F on_select);

private:
    tui::Window &window; ///< The TUI window for rendering

    /**
     * @brief Creates a list of paragraphs from a list of options.
     *
     * @tparam T The type of the options.
     * @param options The list of options to create paragraphs from.
     * @return std::vector<tui::Paragraph> The list of paragraphs.
     */
    template <typename T>
    std::vector<tui::Paragraph> create_paragraphs(const std::vector<T> &options);

    /**
     * @brief Renders a list of paragraphs in the window.
     *
     * @param y_position The y position to display the message.
     * @param paragraphs The paragraphs representing the options.
     * @param highlight The index of the currently highlighted option.
     */
    void render_list(int y_poisiton, const std::vector<tui::Paragraph> &paragraphs, int highlight);

    /**
     * @brief Handles user input for selecting an option.
     *
     * @tparam T The type of the options.
     * @param highlight The index of the currently highlighted option.
     * @param options The list of options to choose from.
     * @return true If the user has selected an option.
     * @return false If the user is still selecting.
     */
    template <typename T>
    bool handle_input(int &highlight, const std::vector<T> &options);
};

// Template function definitions

/**
 * @brief Creates a list of paragraphs from a list of options.
 *
 * @tparam T The type of the options.
 * @param options The list of options to create paragraphs from.
 * @return std::vector<tui::Paragraph> The list of paragraphs.
 */
template <typename T>
std::vector<tui::Paragraph> CoopemonMenu::create_paragraphs(const std::vector<T> &options)
{
    std::vector<tui::Paragraph> paragraphs;
    for (const auto &option : options)
    {
        tui::Paragraph paragraph;
        paragraph.text = option.get_name(); // Assuming T has a get_name() method
        paragraphs.push_back(paragraph);
    }
    return paragraphs;
}

/**
 * @brief Renders a list of paragraphs in the window.
 *
 * @param paragraphs The paragraphs representing the options.
 * @param highlight The index of the currently highlighted option.
 */
template <typename T>
bool CoopemonMenu::handle_input(int &highlight, const std::vector<T> &options)
{
    tui::Event event;
    if (window.poll_event(event))
    {
        if (event.type == tui::KEYDOWN)
        {
            switch (event.key)
            {
            case 38: // Up arrow key
                highlight = (highlight == 0) ? options.size() - 1 : highlight - 1;
                break;
            case 40: // Down arrow key
                highlight = (highlight + 1) % options.size();
                break;
            case 13:         // Enter key for selection
                return true; // Selection complete
            }
        }
    }
    return false; // Continue selecting
}

/**
 * @brief Displays a list of options and allows the user to select one.
 *
 * @tparam T The type of the options.
 * @tparam F The type of the selection handler.
 * @param y_position The y position to display the message.
 * @param message The message to display.
 * @param options The list of options to choose from.
 * @param on_select The selection handler function.
 */
template <typename T, typename F>
void CoopemonMenu::choose_from_list(int y_position, std::string message,
                                    const std::vector<T> &options, F on_select)
{
    auto paragraphs = create_paragraphs(options);
    int highlight = 0; // Currently highlighted option
    bool quit = false;

    while (!quit)
    {
        display_message(window, message, y_position, tui::Color::WHITE, false);
        render_list(y_position + 2, paragraphs, highlight); // Call to non-template function
        quit = handle_input(highlight, options);
        if (quit)
        {
            on_select(options[highlight]); // Call the selection handler
        }
        window.render();
    }

    // window.clear();
}

#endif // MENU_H