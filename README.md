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

- Download the simulator from (http://home.flightgear.org/))[FlightGear.org]

- Run `make` in Terminal from the library `/FlightGear-Simulator/include`.

- Then launch the program `./main`.


The program reads the commands from `FlightInstructions.txt` file.   

The command `make` copy the file `generic_small.xml` into `/usr/share/games/flightgear/Protocol/`, so you don't h 
ave to do that.

> Note that there is a problem with the Heading indicator so that it is not continuously updated, which may affect the direction of the plane

#### Kill the process
Run this `kill -9 $(lsof -ti :5400)`

