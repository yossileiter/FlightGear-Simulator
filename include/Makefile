
CC = g++
OBJS = main.cpp Client.cpp Server.cpp Lexer.cpp Command.cpp parser.cpp Database.cpp 
CFLAGS = -pthread

main:	$(OBJS)
	@echo copying "generic_small.xml"...
	$ sudo cp ../generic_small.xml /usr/share/games/flightgear/Protocol/
	$(CC) -o main $(OBJS) $(CFLAGS)

