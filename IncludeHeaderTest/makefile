# Makefile for IncludeHeaderTest 
#
LINK_TARGET = IncludeHeaderTest.exe
OBJS = main.o ausgabe.o 
REBUILDABLES = $(OBJS) $(LINK_TARGET)

clean :
	rm -f $(REBUILDABLES)
	
all : $(LINK_TARGET)

$(LINK_TARGET) : $(OBJS)
	g++ -g -o $@ $^ 

main.o : src/main.cpp
	g++ -c -g -o main.o src/main.cpp

ausgabe.o : src/ausgabe.cpp src/ausgabe.hpp 
	g++ -c -g -o ausgabe.o src/ausgabe.cpp