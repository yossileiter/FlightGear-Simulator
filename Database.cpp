#include "Database.hpp"

Database *Database::instance = 0;

Database *Database::getInstance()   //create a singleton
{
	if(!instance) instance = new Database();
	return instance;
}