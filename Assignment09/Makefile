CPPFILES = EC2DShape.cpp EC2DShapeMain.cpp

HFILES = $(CPPFILES:.cpp=.h)

OFILES= $(CPPFILES:.cpp=.o)

CC = g++
LIBPATH =

CFLAGS = -O3 -std=c++11 -Wall -I.

all: runThis

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

runThis:$(OFILES)
	$(CC) -o runThis $(OFILES)

clean: 
	rm *.o
	rm runThis