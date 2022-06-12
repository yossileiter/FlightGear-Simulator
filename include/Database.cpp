#include "Database.hpp"

Database *Database::instance = 0;

Database *DATABASE   //create a singleton
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
    Command *UnknownCommand = new unknownCommand();

    DATABASE->CommandMap["connect"] = ConnectCommand;
    DATABASE->CommandMap["openDataServer"] = OpenServerCommand;
    DATABASE->CommandMap["var"] = VarCommand;
    DATABASE->CommandMap["="] = SetCommand;
    DATABASE->CommandMap["print"] = PrintCommand;
    DATABASE->CommandMap["sleep"] = SleepCommand;
    DATABASE->CommandMap["while"] = WhileCommand;
    DATABASE->CommandMap["unknownCommand"] = UnknownCommand;
}
