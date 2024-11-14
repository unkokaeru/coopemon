/**
 * @file battle.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Implementation of the Coopemon battle system.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "battle.h"
#include <cstdio>
#include "Dialogue.h"
#include "menu.h"
#include "messaging.h"
#include "Move.h"
#include "prompting.h"

/**
 * @brief Construct a new Battle:: Battle object.
 *
 * @param player
 * @param enemy
 * @param win
 */
Battle::Battle(Coopemon &player, Coopemon &enemy, tui::Window &win)
    : playerCoopemon(player), enemyCoopemon(enemy), window(win), quit(false) {}

/**
 * @brief Perform the battle loop.
 *
 */
void Battle::start()
{
    while (!quit)
    {
        window.clear();
        display_battle_info();
        int y_position = 4;
        window.render();
        sleep_for(1000);

        y_position = perform_turn(playerCoopemon, enemyCoopemon, Dialogue::PLAYER_TURN,
                                  tui::Color::GREEN, y_position);
        if (quit)
            break;

        window.render();
        sleep_for(1000);

        y_position = perform_turn(enemyCoopemon, playerCoopemon, Dialogue::ENEMY_TURN,
                                  tui::Color::RED, y_position);
        if (quit)
            break;

        window.render();
        sleep_for(1000);

        prompt_continue(window, Dialogue::CONTINUE_PROMPT, ' ');
    }
}

/**
 * @brief Perform a turn in the battle.
 *
 * @param attacker
 * @param defender
 * @param dialogue
 * @param colour
 * @param y_position
 * @return y_position The updated y position.
 */
int Battle::perform_turn(Coopemon &attacker, Coopemon &defender,
                         const std::string &dialogue, tui::Color colour, int y_position)
{
    if (attacker.is_fainted() || defender.is_fainted())
        return y_position;

    char action_message[100];
    snprintf(action_message, sizeof(action_message), dialogue.c_str(),
             attacker.get_name().c_str(), defender.get_name().c_str());
    display_message(window, action_message, y_position, colour, false);
    y_position += 1;
    window.render();
    sleep_for(1000);

    Move attacking_move("None", 0);
    if (attacker.is_controlled())
    {
        attacking_move = attacker.display_moves(window, y_position);
        y_position += attacker.get_moves().size() + 3;
    }
    else
    {
        // Randomly select a move
        std::vector<Move> moves = attacker.get_moves();
        attacking_move = moves[rand() % moves.size()];
    }

    char move_message[100];
    snprintf(move_message, sizeof(move_message), Dialogue::USED_MOVE.c_str(),
             attacker.get_name().c_str(), attacking_move.get_name().c_str());
    display_message(window, move_message, y_position, colour, false);
    y_position += 1;
    window.render();
    sleep_for(1000);
    defender.take_damage(attacking_move.get_power());
    if (defender.is_fainted())
    {
        defender.display_faint_message(window, y_position);
        y_position += 1;
        display_result(attacker, y_position);
        prompt_continue(window, Dialogue::EXIT_PROMPT, 'q');
        quit = true;
    }
    else
    {
        defender.display_health_status(window, y_position);
        y_position += 3;
    }

    return y_position;
}

void Battle::display_battle_info()
{
    // Format the battle information
    char battle_info[100];
    snprintf(battle_info, sizeof(battle_info), Dialogue::BATTLE_INFO.c_str(),
             playerCoopemon.get_name().c_str(), playerCoopemon.get_health(),
             enemyCoopemon.get_name().c_str(), enemyCoopemon.get_health());

    display_message(window, battle_info, 1, tui::Color::WHITE, true);
}

/**
 * @brief Displays the result of a battle.
 *
 * @param coopemon
 * @param y_position
 */
void Battle::display_result(const Coopemon &coopemon, int y_position)
{
    char result_message[100];
    snprintf(result_message, sizeof(result_message),
             (coopemon.is_fainted() && &coopemon == &playerCoopemon)
                 ? Dialogue::PLAYER_DEFEAT.c_str()
                 : Dialogue::PLAYER_VICTORY.c_str());
    y_position += 2;
    display_message(window, result_message, y_position, tui::Color::WHITE, false);
}

/**
 * @brief Performs a battle between two Coopemons.
 *
 * @param playerCoopemon A reference to the player's Coopemon.
 * @param enemyCoopemon A reference to the enemy Coopemon.
 * @param window The TUI window for rendering.
 */
void battle(Coopemon &playerCoopemon, Coopemon &enemyCoopemon, tui::Window &window)
{
    Battle battleSystem(playerCoopemon, enemyCoopemon, window);
    battleSystem.start();
}