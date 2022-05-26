<p align="center">
  <img 
    align="right"
    width="167"
    height="222"
    src="https://wiki.flightgear.org/w/images/0/00/Fglogo1.png"
  >
</p>


# FlightGear-Simulator

### Getting Started

This interpreter allows you to fly the plane in the flight simulator.

You can download the simulator from `http://home.flightgear.org/`

In the `Settings` screen, add the following lines in `additional settings`

`--telnet=socket,in,10,127.0.0.1,5402,tcp`  
`--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small`


First of all run `make` from the library `FlightGear-Simulator/include`,  and then `./main` and then launch the FlightGear.

Make sure you have the file `generic_small.xml` in `/usr/share/games/flightgear/Protocol/`. 

The `main` file reads the commands from `FlightInstructions.txt` file.

### Kill the process
Run this `kill -9 $(lsof -ti :5400)`

