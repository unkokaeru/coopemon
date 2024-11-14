/**
 * @file main.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Main program entry point for the Coopemon game.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <vector>
#include <cstdlib>
#include <ctime>
#include <tui.hpp>
#include "Coopemon.h"
#include "Trainer.h"
#include "Paths.h"
#include "battle.h"
#include "menu.h"
#include "messaging.h"
#include "JsonUtilities.h"
#include "prompting.h"

int main()
{
    // Set up the application
    srand(static_cast<unsigned int>(time(0)));

    std::vector<Coopemon> available_coopemons;
    load_coopemons(Paths::COOPEMONS_JSON, available_coopemons);

    std::vector<Coopemon> starter_coopemons;
    for (size_t index = 0; index < 3; ++index)
    {
        starter_coopemons.push_back(available_coopemons[index]);
    }

    tui::Window window;
    window.set_title("Coopemon");

    // Choose a starter Coopemon
    CoopemonMenu menu(window);
    Coopemon playerCoopemon(true, "None", 0, {});
    menu.choose_from_list(1, Dialogue::CHOOSE_COOPEMON, starter_coopemons,
                          [&](const Coopemon &selected)
                          { playerCoopemon = selected; });
    window.clear();

    // Create a random encounter
    Trainer trainer("Dr. Bilbo");
    trainer.add_coopemon(available_coopemons[rand() % available_coopemons.size()]);

    char intro_text[100];
    snprintf(intro_text, sizeof(intro_text), Dialogue::BATTLE_INTRO.c_str(),
             trainer.get_name().c_str(), trainer.get_name().c_str(),
             trainer.get_random_coopemon().get_name().c_str());
    display_message(window, intro_text, 1, tui::Color::WHITE, true);
    prompt_continue(window, Dialogue::CONTINUE_PROMPT, ' ');

    Coopemon enemyCoopemon = trainer.get_random_coopemon();
    battle(playerCoopemon, enemyCoopemon, window);

    std::vector<Coopemon> player_party = {playerCoopemon}; // TODO: Add captured Coopemons
    save_party(Paths::PLAYER_PARTY_JSON, player_party);

    return 0;
}