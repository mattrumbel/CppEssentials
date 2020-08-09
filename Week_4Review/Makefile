CPPFILES = ECReviewMain.cpp

HFILES = $(CPPFILES:.cpp=.h)

OFILES= $(CPPFILES:.cpp=.o)

CC = g++
LIBPATH =

CFLAGS = -O3 -std=c++11 -Wall -I.

all: ECReviewMain

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

ECReviewMain:$(OFILES)
	$(CC) -o runThis $(OFILES)

clean: 
	rm *.o
	rm runThis