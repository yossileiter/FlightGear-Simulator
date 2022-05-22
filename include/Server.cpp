#include "Server.hpp"
#include "Database.hpp"

Server *Server::instance = 0;
Server *Server::getInstance()
{
	if (!instance) instance = new Server;
	return instance;
}

void Server::SplitLine(string line) 		//split a line into words
    {	
        string temp = "";
        for(int i=0 ;i<line.length(); ++i)
        {
            if(line[i]==',')
            {
                values.push_back(stod(temp));
                temp = "";
            }
            else { temp.push_back(line[i]); }		
        }
        values.push_back(stod(temp));	
		// PrintVector(values);
    };

void Server::PrintVector(vector<double> v) //print a vector
    {
        for(int i=0;i<v.size();++i)
            cout<<v[i]<<endl;
        cout<<"\n";
    }

void Server::Connect(int port, const char *ip)
{
	cout << "Waiting for the Simulator..." << endl;

	struct sockaddr_in address;
	int addrlen = sizeof(address);

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port PORT
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	// Forcefully attaching socket to the port PORT
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

	while (true)
	{
		valread = read(new_socket, buffer, 4096);
		SplitLine(buffer);
		
		for (size_t i = 0; i < paths.size(); i++)
		{
			Database::getInstance()->SymbolTable[paths[i]] = values[i];
			// cout << Database::getInstance()->SymbolTable[paths[i]] << ": " << values[i] <<endl;
		}

		// for (auto const &pair: Database::getInstance()->SymbolTable)
		// {
		// 	cout << pair.second << ", ";
		// }
		// cout << endl << buffer <<endl;
		// cout <<"\n\n";


		// PrintVector(data);
		// ofstream myfile("DataBase.txt");
		// if (myfile.is_open())
		// {
		// 	myfile << buffer << endl;
		// 	myfile.close();
		// }
		// else cout << "Unable to open file";
	}
}
