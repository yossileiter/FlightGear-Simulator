#include "parser.hpp"
#include "Client.hpp"
#include "Server.hpp"

void Lexer::SplitLine(string s)
    {	
        string temp = "";
        for(int i=0 ;i<s.length(); ++i)
        {
            if(s[i]==' ')
            {
                v.push_back(temp);
                temp = "";
            }
            else { temp.push_back(s[i]); }		
        }
        v.push_back(temp);	
    };


void Lexer::PrintVector(vector<string> v)
    {
        for(int i=0;i<v.size();++i)
            cout<<"line "<<i<<": "<<v[i]<<endl;
        cout<<"\n";
    }

void Lexer::ReadInstructions(string FilePath)
{
    fstream newfile;
    newfile.open(FilePath,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) //checking whether the file is open
    { 
        string line;
        while(getline(newfile, line)) //read data from file object and put it into string.
        { 
            // cout << line << "\n"; //print the data of the string  
            AllLines.push_back(line);
        }
        newfile.close(); //close the file object.
    }
}

void openServerCommand::doCommand()
{
    Server *server = Server::getInstance();
    int port = stoi(v[1]);
    const char* ip = "127.0.0.1";
    server->Connect(port, ip);

}

void connectCommand::doCommand()
{
    Client *client = Client::getInstance();
    const char* ip = v[1].c_str();
    int port = stoi(v[2]);
    client->Connect(port, ip);
}

void Parser::parse(vector<string> v)
{
    string command = v[0];
    
    if (command == "connect")
    {
        
        connectCommand *ConnectCommand = new connectCommand();
        ConnectCommand->doCommand();
    }
    else if (command == "openDataServer")
    {
        openServerCommand *OpenServerCommand = new openServerCommand();
        OpenServerCommand->doCommand();    
        
    }
    else    cout<<"Illegal command"<<endl;
}

// -------------------------------------command-------------------------------------------- //

// Command Interface

 
// Receiver Class
class Light 
{
public:
	void on() {
		cout << "The light is on\n";
	}
	void off() {
		cout << "The light is off\n";
	}
}; 

// Command for turning on the light
class LightOnCommand : public Command 
{
public:
        LightOnCommand(Light *light) : mLight(light) {}
	void doCommand(){
		mLight->on();
	}
private:
	Light *mLight;
};
 
// Command for turning off the light
class LightOffCommand : public Command 
{
public:
        LightOffCommand(Light *light) : mLight(light) {}
	void doCommand(){
		mLight->off();
	}
private:
	Light *mLight;
};

// Invoker 
// Stores the ConcreteCommand object 
class RemoteControl 
{
public:
	void setCommand(Command *cmd) {
		mCmd = cmd;
	}

	void buttonPressed() {
		mCmd->doCommand();
	} 
private:
	Command *mCmd;
};
 