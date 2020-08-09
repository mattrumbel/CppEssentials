CPPFILES = ECSquareMat.cpp ECSquareMatMain.cpp

HFILES = $(CPPFILES:.cpp=.h)

OFILES= $(CPPFILES:.cpp=.o)

CC = g++
LIBPATH =

CFLAGS = -O3 -std=c++11 -Wall -I. 

all: SquareMat

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

SquareMat:$(OFILES)
	$(CC) -o SquareMat $(OFILES)

clean: 
	rm *.o
	rm SquareMat