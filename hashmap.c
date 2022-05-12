#include <unordered_map>
#include <iostream>
using namespace std;
int main()
{
    std::unordered_map<std::string, int> age;
    // Insert
    age["Eric"] = 16;
    age.insert(std::pair<std::string, int>{"Bill", 25});
    age.insert({"Chris", 30});

    // Search and change
    age["Eric"] = 18;
    age.at("Chris") = 27;

    // Check if key exists
    std::string query;
    query = "Eric";
    std::cout << age.at(query) << std::endl;

    cout<< age[query]<<endl;
    cout << age.find(query)->second<<"find"<<endl;
    if (age.find(query) != age.end())
    {
        std::cout << age.at(query) << std::endl;
    }

    // Delete
    query = "Michael";
    if (age.find(query) == age.end())
    {
        std::cout << query << " is not in the dictionary!" << std::endl;
    }
    age.erase(query);
    if (age.find(query) == age.end())
    {
        std::cout << query << " is not in the dictionary!" << std::endl;
    }

    // Iterate
    for (const std::pair<std::string, int>& tup : age)
    {
        std::cout << "Name: " << tup.first << std::endl;
        std::cout << "Age: " << tup.second << std::endl;
    }
}
