#include <stdio.h>
#include <string>
#include <iostream>

using namespace std; 


class singleton
{
private:
    singleton() {}
public:
    static singleton& get()
    {
        static Client* instance;
		socket soc = 0;
        Client();
    }

}
