#include "Database.hpp"

Database *Database::instance = 0;

Database *Database::getInstance()   //create a singleton
{
	if(!instance) instance = new Database();
	return instance;
}

unordered_map <string, Command*> Database::CommandMap;
unordered_map <string, double> Database::SymbolTable;
unordered_map <string, string> Database::VarTable;

void Database::buildmap()
{
    Command *ConnectCommand = new connectCommand();
    Command *OpenServerCommand = new openServerCommand();
    Command *VarCommand = new varCommand();

    Database::getInstance()->CommandMap["connect"] = ConnectCommand;
    Database::getInstance()->CommandMap["openDataServer"] = OpenServerCommand;
    Database::getInstance()->CommandMap["var"] = VarCommand;
}

// unordered_map<string, Command*> CommandMap;      // key: command NAME, value: command OBJECT
//     static unordered_map<string, double> SymbolTable; // key: Flight DEVICES, value: VALUE in numbers
//     unordered_map<string, string> VarTable;    // key: Flight device NAME, value: Flight device PATH
