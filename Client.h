#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

using namespace std;

class Client
{
private:
    static Client* instance;

public:
    Client() {};
    Client* getInstance()
    {
        if (instance == 0) instance = new Client();
        return instance;
    }
	void Connect(int port, const char* ip);
    ~Client();
};
