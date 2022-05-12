
CC = g++
OBJS = main.cpp Client.cpp Server.cpp Lexer.cpp Command.cpp parser.cpp Database.cpp


main:	$(OBJS)
	$(CC) -o main $(OBJS)

