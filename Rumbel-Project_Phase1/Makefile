CPPFILES = Commands.cpp Document.cpp ECEditorTest.cpp ECTextViewImp.cpp EditorController.cpp

HFILES = $(CPPFILES:.cpp=.h)

OFILES= $(CPPFILES:.cpp=.o)

CC = g++
LIBPATH =

CFLAGS = -O3 -std=c++14 -Wall -I.

all: runThis

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

runThis:$(OFILES)
	$(CC) -o runThis $(OFILES)

clean: 
	rm *.o
	rm runThis
	clear