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

Download the simulator from `http://home.flightgear.org/`

Make sure you have the file `generic_small.xml` in `/usr/share/games/flightgear/Protocol/`. 

- Run `make` in Terminal from the library `/FlightGear-Simulator/include`.

- Then launch the program `./main`.


The `main` file reads the commands from `FlightInstructions.txt` file.


> Note that there is a problem with the Heading indicator so that it is not continuously updated, which may affect the direction of the plane

#### Kill the process
Run this `kill -9 $(lsof -ti :5400)`

