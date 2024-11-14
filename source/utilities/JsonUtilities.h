/**
 * @file JsonUtilities.h
 * @author William Fayers (william@fayers.com)
 * @brief Utility functions for loading and saving Coopemons to JSON files.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef JSONUTILITIES_H
#define JSONUTILITIES_H

#include <vector>
#include <string>
#include "Coopemon.h"
#include "Move.h"

/**
 * @brief Loads Coopemons from a JSON file.
 *
 * @param filename The name of the file to load Coopemons from.
 * @param coopemons A reference to a vector where the loaded Coopemons will be stored.
 */
void load_coopemons(const std::string &filename, std::vector<Coopemon> &coopemons);

/**
 * @brief Saves a party of Coopemons to a JSON file.
 *
 * @param filename The name of the file to save the party to.
 * @param party A constant reference to a vector of Coopemons representing the party.
 */
void save_party(const std::string &filename, const std::vector<Coopemon> &party);

#endif // JSONUTILITIES_H