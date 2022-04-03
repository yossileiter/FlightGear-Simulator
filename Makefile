
CC = g++
OBJS = main.cpp Client.cpp Server.cpp


inter:	$(OBJS)
	$(CC) -o inter $(OBJS)

