# FlightGear-Simulator

### Getting Started

This interpreter allows you to fly the plane in the flight simulator.

You can download the simulator from `http://home.flightgear.org/`

In the `Settings` screen, add the following lines in `additional settings`

`--telnet=socket,in,10,127.0.0.1,5402,tcp`  
`--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small`


First of all run `make` and then `./main`.

Make sure you have the file `generic_small.xml` in `/usr/share/games/flightgear/Protocol/`. 

The `main` file reads the commands from `FlightInstructions.txt` file.

### Server
If you want to run the SERVER, the first line must be `server 5400 127.0.0.1`

### Client
If you want to run the CLIENT, the first line must be `client 5402 127.0.0.1`

