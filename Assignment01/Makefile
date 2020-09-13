CPPFILES = ECLongestPrefix.cpp ECLongestPrefixTest.cpp

HFILES = $(CPPFILES:.cpp=.h)

OFILES= $(CPPFILES:.cpp=.o)

CC = g++
LIBPATH =

CFLAGS = -O3 -std=c++11 -Wall -I. 

all: LongestPrefix

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

LongestPrefix:$(OFILES)
	$(CC) -o LongestPrefix $(OFILES)

clean: 
	rm *.o
	rm LongesetPrefix