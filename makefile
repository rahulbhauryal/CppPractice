# Makefile for building myprogram

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++17

# Default target
all: myprogram

# Rule to build the myprogram executable
myprogram: main.o play01Templates.o playground.o
	$(CC) $(CFLAGS) main.o play01Templates.o playground.o -o myprogram

# Rule to compile main.cpp into object file main.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

# Rule to compile play01Templates.cpp into object file play01Templates.o
play01Templates.o: play01Templates.cpp
	$(CC) $(CFLAGS) -c play01Templates.cpp

# Rule to compile playground.cpp into object file playground.o
playground.o: playground.cpp
	$(CC) $(CFLAGS) -c playground.cpp

# Rule to clean the project by removing object files and the executable
clean:
ifeq ($(OS),Windows_NT)
	del *.o myprogram
else
	rm -f *.o myprogram
endif
