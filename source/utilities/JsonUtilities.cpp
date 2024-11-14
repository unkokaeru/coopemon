/**
 * @file JsonUtilities.cpp
 * @author William Fayers (william@fayers.com)
 * @brief Utility functions for loading and saving Coopemons to JSON files.
 * @version 0.1.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "JsonUtilities.h"
#include <fstream>
#include "json.hpp"
#include "Coopemon.h"
#include "Paths.h"
#include "Move.h"

using json = nlohmann::json_abi_v3_11_3::json;

/**
 * @brief Loads Coopemons from a JSON file.
 *
 * @param filename The name of the file to load Coopemons from.
 * @param coopemons A reference to a vector where the loaded Coopemons will be stored.
 */
void load_coopemons(const std::string &filename, std::vector<Coopemon> &coopemons)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    json json_data;
    try
    {
        file >> json_data;
    }
    catch (const json::parse_error &e)
    {
        throw std::runtime_error("JSON parse error: " + std::string(e.what()));
    }

    for (const auto &item : json_data)
    {
        std::vector<Move> moves;
        for (const auto &move_item : item["moves"])
        {
            std::string move_name = move_item["name"];
            int move_power = move_item["power"];
            moves.emplace_back(move_name, move_power);
        }
        coopemons.emplace_back(true, item["name"], item["health"], moves);
    }
}

/**
 * @brief Saves a party of Coopemons to a JSON file.
 *
 * @param filename The name of the file to save the party to.
 * @param party A constant reference to a vector of Coopemons representing the party.
 */
void save_party(const std::string &filename, const std::vector<Coopemon> &party)
{
    json json_data;
    for (const auto &coopemon : party)
    {
        json coopemon_data = {
            {"controlled", coopemon.is_controlled()},
            {"name", coopemon.get_name()},
            {"health", coopemon.get_health()},
            {"moves", json::array()} // Initialize an empty array for moves
        };

        for (const auto &move : coopemon.get_moves())
        {
            coopemon_data["moves"].push_back({{"name", move.get_name()},
                                              {"power", move.get_power()}});
        }

        json_data.push_back(coopemon_data);
    }

    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file for writing: " + filename);
    }

    try
    {
        file << json_data.dump(4); // Pretty print with 4 spaces
    }
    catch (const std::exception &error)
    {
        throw std::runtime_error("Error writing to file: " + std::string(error.what()));
    }
}