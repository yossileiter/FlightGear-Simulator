
CC = g++
OBJS = main.cpp Client.cpp Server.cpp #parser.cpp


inter:	$(OBJS)
	$(CC) -o main $(OBJS)

