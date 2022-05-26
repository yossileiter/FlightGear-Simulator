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

void Database::buildCommandMap()
{
    Command *ConnectCommand = new connectCommand();
    Command *OpenServerCommand = new openServerCommand();
    Command *VarCommand = new varCommand();
    Command *SetCommand = new setCommand();
    Command *PrintCommand = new printCommand();
    Command *SleepCommand = new sleepCommand();
    Command *WhileCommand = new whileCommand();

    Database::getInstance()->CommandMap["connect"] = ConnectCommand;
    Database::getInstance()->CommandMap["openDataServer"] = OpenServerCommand;
    Database::getInstance()->CommandMap["var"] = VarCommand;
    Database::getInstance()->CommandMap["set"] = SetCommand;
    Database::getInstance()->CommandMap["print"] = PrintCommand;
    Database::getInstance()->CommandMap["sleep"] = SleepCommand;
    Database::getInstance()->CommandMap["while"] = WhileCommand;
}


