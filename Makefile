CXX = g++ -fPIC

all: IRCServer

IRCServer: IRCServer.cpp
	g++ -Wall -Werror -o IRCServer IRCServer.cpp

clean:
	rm -f *.out
	rm -f *.o IRCServer
