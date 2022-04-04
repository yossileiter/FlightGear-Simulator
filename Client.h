#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace std;

class Client
{
private:
    static Client* instance;

public:
    Client(){}
    static Client *getInstance()
{
        if (instance == 0) instance = new Client();
        return instance;
		cout<<"instance is: "<<instance<<endl;
}
	void Connect(int port, const char* ip);
    ~Client();
};

// Client* Client::instance = 0;
// Client *Client::getInstance()
// Client::Client(){};

// class Connect : public Command
// {
// public:
//     Connect();
// };

// void Connect::do_command()
// {
//     Client::getInstance()->Connect(port, ip);
// }