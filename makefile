# Makefile for building myprogram
# Directories

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

SRC_DIR = src
APP_DIR = $(SRC_DIR)/app

# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -Wextra -std=c++17


# Files
TARGET = $(BIN_DIR)/myprogram
SOURCES = $(SRC_DIR)/main.cpp \
		$(APP_DIR)/play01Templates.cpp \
		$(APP_DIR)/playground.cpp
		
# create object variable from the sources variables
OBJECT_NAMES = $(SOURCES:.cpp=.o)
OBJECTS = $(patsubst %,$(OBJ_DIR)/%,$(OBJECT_NAMES))


# Build
## linking
$(TARGET): $(OBJECTS)
# TODO: mkdir is not working somehow :(
#	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

## compiling
# -c: The flag passed to the compiler to indicate that the input file should be compiled into an object file, rather than an executable.
# -o $@: The -o flag followed by $@, which is a special variable representing the target name (the object file being generated). This specifies the output file name for the compiler.
# $^: A special variable representing all the prerequisites (dependencies) of the rule. In this case, it refers to the source file (%.cpp), which is the input file for the compiler.
$(OBJ_DIR)/%.o: %.cpp
#	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $^

# phonies
.PHONY: all clean

all: $(TARGET)

# Cppcheck target
cppcheck:
	cppcheck --enable=all --inconclusive --std=c++17 $(SOURCES)													

# Rule to clean the project by removing object files and the executable
clean:
ifeq ($(OS),Windows_NT)
	del /Q "$(OBJ_DIR)\*.o"
	del /Q "$(TARGET)"
else
	rm -f $(OBJ_DIR)/*.o
	rm -f $(TARGET)
endif
