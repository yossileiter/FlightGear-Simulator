
CC = g++
OBJS = interpreter.cpp Client.cpp Server.cpp


inter:	$(OBJS)
	$(CC) -o inter $(OBJS)

