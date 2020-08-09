CPPFILES = ECGraph.cpp ECGraphMain.cpp

HFILES = $(CPPFILES:.cpp=.h)

OFILES= $(CPPFILES:.cpp=.o)

CC = g++
LIBPATH =

CFLAGS = -O3 -std=c++11 -Wall -I.

all: Graph

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

Graph:$(OFILES)
	$(CC) -o Graph $(OFILES)

clean: 
	rm *.o
	rm Graph