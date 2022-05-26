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

void Database::buildSymbolMap()
{
    SymbolTable["/sim/time/warp"] = 0;
    SymbolTable["/sim/model/c172p/brake-parking"] = 0;

    SymbolTable["/instrumentation/airspeed-indicator/indicated-speed-kt"] = 0;
    SymbolTable["/instrumentation/heading-indicator/offset-deg"] = 98;
    SymbolTable["/instrumentation/altimeter/indicated-altitude-ft"] = 120;
    SymbolTable["/instrumentation/altimeter/pressure-alt-ft"] = 0;
    SymbolTable["/instrumentation/attitude-indicator/indicated-pitch-deg"] = 3.2;
    SymbolTable["/instrumentation/attitude-indicator/indicated-roll-deg"] = 2;
    SymbolTable["/instrumentation/attitude-indicator/internal-pitch-deg"] = 3.7;
    SymbolTable["/instrumentation/attitude-indicator/internal-roll-deg"] = 0;
    SymbolTable["/instrumentation/encoder/indicated-altitude-ft"] = 0;
    SymbolTable["/instrumentation/encoder/pressure-alt-ft"] = 0;
    SymbolTable["/instrumentation/gps/indicated-altitude-ft"] = 0;
    SymbolTable["/instrumentation/gps/indicated-ground-speed-kt"] = 0;
    SymbolTable["/instrumentation/gps/indicated-vertical-speed"] = 0;
    SymbolTable["/instrumentation/heading-indicator/indicated-heading-deg"] = 0;
    SymbolTable["/instrumentation/magnetic-compass/indicated-heading-deg"] = 0;
    SymbolTable["/instrumentation/slip-skid-ball/indicated-slip-skid"] = 0;
    SymbolTable["/instrumentation/turn-indicator/indicated-turn-rate"] = 0;
    SymbolTable["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = 0;

    SymbolTable["/controls/flight/aileron"] = 0;
    SymbolTable["/controls/flight/elevator"] = 0;
    SymbolTable["/controls/flight/rudder"] = 0;
    SymbolTable["/controls/flight/flaps"] = 0;
    SymbolTable["/controls/flight/speedbrake"] = 0; 

    SymbolTable["/controls/engines/engine/throttle"] = 0;
    SymbolTable["/controls/engines/current-engine/throttle"] = 0;
    SymbolTable["/controls/engines/engine/primer"] = 0;
    SymbolTable["/controls/engines/current-engine/mixture"] = 0;

    SymbolTable["/controls/switches/master-avionics"] = 0; 
    SymbolTable["/controls/switches/magnetos"] = 0;
    SymbolTable["/controls/switches/master-bat"] = 0; 
    SymbolTable["/controls/switches/master-alt"] = 0;
    SymbolTable["/controls/switches/starter"] = 0;

    SymbolTable["/engines/active-engine/auto-start"] = 0;
    SymbolTable["/engines/engine/rpm"] = 0;

    cout << "SymbolTable created successfully" << endl;
}

