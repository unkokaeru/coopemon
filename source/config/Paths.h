/**
 * @file paths.h
 * @author William Fayers (william@fayers.com)
 * @brief Paths to data files used by the Coopemon game.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef PATHS_H
#define PATHS_H

#include <string>

namespace Paths
{
    const std::string COOPEMONS_JSON = "../../data/coopemons.json";       ///< Coopemons JSON.
    const std::string PLAYER_PARTY_JSON = "../../data/player_party.json"; ///< Player's party JSON.
}

#endif // PATHS_H