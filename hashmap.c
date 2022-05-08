#include <unordered_map>
#include <iostream>
#include "Command.hpp"

int parsing(vector<string> v)
{
    Command *commands = new openServerCommand;
    std::unordered_map<std::string, Command> CommandsMap;
    // Insert
    CommandsMap["Michael"] = 16;
    // CommandsMap.insert(std::pair<std::string, int>{"Bill", 25});
    CommandsMap.insert({"Chris", 30});

    // Search and change
    CommandsMap["Michael"] = 18;
    CommandsMap.at("Chris") = 27;

    // Check if key exists
    std::string query;
    query = "Eric";
    if (CommandsMap.find(query) == CommandsMap.end())
    {
        std::cout << query << " is not in the dictionary!" << std::endl;
    }

    // Delete
    query = "Michael";
    if (CommandsMap.find(query) == CommandsMap.end())
    {
        std::cout << query << " is not in the dictionary!" << std::endl;
    }
    CommandsMap.erase(query);
    if (CommandsMap.find(query) == CommandsMap.end())
    {
        std::cout << query << " is not in the dictionary!" << std::endl;
    }

    // Iterate
    for (const std::pair<std::string, int>& tup : CommandsMap)
    {
        std::cout << "Name: " << tup.first << std::endl;
        std::cout << "CommandsMap: " << tup.second << std::endl;
    }
}
