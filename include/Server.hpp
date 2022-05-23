#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <thread>
#include <map>

using namespace std;

class Server
{
private:
    Server() {}
    static Server *instance;
    int server_fd, new_socket, valread;
	int opt = 1;
	char buffer[4096] = {0};
    vector<string> paths = {"/instrumentation/airspeed-indicator/indicated-speed-kt","/sim/time/warp","/controls/switches/magnetos","/instrumentation/heading-indicator/offset-deg","/instrumentation/altimeter/indicated-altitude-ft","/instrumentation/altimeter/pressure-alt-ft","/instrumentation/attitude-indicator/indicated-pitch-deg","/instrumentation/attitude-indicator/indicated-roll-deg","/instrumentation/attitude-indicator/internal-pitch-deg","/instrumentation/attitude-indicator/internal-roll-deg","/instrumentation/encoder/indicated-altitude-ft","/instrumentation/encoder/pressure-alt-ft","/instrumentation/gps/indicated-altitude-ft","/instrumentation/gps/indicated-ground-speed-kt","/instrumentation/gps/indicated-vertical-speed","/instrumentation/heading-indicator/indicated-heading-deg","/instrumentation/magnetic-compass/indicated-heading-deg","/instrumentation/slip-skid-ball/indicated-slip-skid","/instrumentation/turn-indicator/indicated-turn-rate","/instrumentation/vertical-speed-indicator/indicated-speed-fpm","/controls/flight/aileron","/controls/flight/elevator","/controls/flight/rudder","/controls/flight/flaps","/controls/engines/engine/throttle","/controls/engines/current-engine/throttle","/controls/switches/master-avionics","/controls/switches/starter","/engines/active-engine/auto-start","/controls/flight/speedbrake" ,"/sim/model/c172p/brake-parking","/controls/engines/engine/primer","/controls/engines/current-engine/mixture","/controls/switches/master-bat","/controls/switches/master-alt","/engines/engine/rpm"};
    void PrintVector(vector<double> v);
    vector <double> SplitLine(string s);

public:
    static Server *getInstance();
    void Connect(int port, const char *ip);
    // void ListeningToSimulator();
    thread t1;
    ~Server();
};

#endif