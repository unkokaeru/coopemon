/**
 * @file Dialogue.h
 * @author William Fayers (william@fayers.com)
 * @brief Header file for the Coopemon dialogue constants.
 * @version 0.1.0
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>

namespace Dialogue
{
    const std::string BATTLE_INTRO = "You are challenged by Trainer %s! Trainer %s sent out %s!";
    const std::string PLAYER_TURN = "%s attacks %s!";
    const std::string ENEMY_TURN = "%s attacks %s!";
    const std::string FAINT_MESSAGE = "%s fainted!";
    const std::string PLAYER_DEFEAT = "You were defeated! Better luck next time!";
    const std::string PLAYER_VICTORY = "Congratulations! You won the battle!";
    const std::string HEALTH_STATUS = "%s has %d HP remaining.";
    const std::string BATTLE_INFO = "%s (HP: %d) vs %s (HP: %d)";
    const std::string CONTINUE_PROMPT = "Press space to continue...";
    const std::string EXIT_PROMPT = "Press Q to exit...";
    const std::string CHOOSE_COOPEMON = "Choose your starter Coopemon:";
    const std::string CHOOSE_MOVE = "Choose a move:";
    const std::string USED_MOVE = "%s used %s!";
}

#endif // DIALOGUE_H
