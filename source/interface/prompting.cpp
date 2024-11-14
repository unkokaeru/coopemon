/**
 * @file prompting.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Implementation of the Coopemon prompting utilities.
 * @version 0.1.0
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "prompting.h"

/**
 * @brief Waits for the given key to be pressed.
 */
void wait_for_key(tui::Window &window, char key)
{
    tui::Event event;
    while (true)
    {
        if (window.poll_event(event))
        {
            if (event.type == tui::KEYDOWN && event.key == key)
            {
                break; // Exit the loop
            }
        }
    }
}

/**
 * @brief Displays a prompt at the bottom of the window asking the user to press a key to continue.
 */
void prompt_continue(tui::Window &window, std::string prompt_text, char key)
{
    tui::Paragraph prompt_paragraph;
    prompt_paragraph.text = prompt_text;
    prompt_paragraph.set_dimensions(1, window.rows() - 2, prompt_text.length() + 2, 3);
    window.add(prompt_paragraph);
    window.render();

    wait_for_key(window, key); // Wait for the user to press the key
}