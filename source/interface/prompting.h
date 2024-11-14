/**
 * @file prompting.h
 * @author William Fayers (william@fayers.com)
 * @brief Header file for the Coopemon prompting utilities.
 * @version 0.1.0
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef PROMPTING_H
#define PROMPTING_H

#include "tui.hpp"
#include <string>
#include "Dialogue.h"

void wait_for_key(tui::Window &window, char key);
void prompt_continue(tui::Window &window, std::string prompt_text, char key);

#endif // PROMPTING_H