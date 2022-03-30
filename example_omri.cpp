#include <sys/socket.h>
#include <string.h>

class Client
{
    private:
        static Client* instance;
		socket soc = 0;
        Client();
    public:
        /* Static access method. */
        static Client* getInstance();
		void connect(int port, std::string ip);
		void send(? data);
};


/* Null, because instance will be initialized on demand. */
Client* Client::instance = 0;
Client* Client::getInstance()
{
    if (instance == 0)
    {
        instance = new Client();
    }
    return instance;
}
Client::Client()
{}


class Connect : Command {
public:
	Connect(int port, std::string ip);
	void do_command();
private:
	int port;
	std:string ip;
}
Connect::Connect(int port, std::string ip) {
	port = port;
	ip = ip;
}
void Connect::do_command() {
	Client.getInstance()->connect(port, ip);
}










