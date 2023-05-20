# Makefile for building myprogram
# Directories

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -Wextra -std=c++17


# Files
TARGET = $(BIN_DIR)/myprogram
SOURCES = main.cpp \
		play01Templates.cpp \
		playground.cpp
OBJECTS = $(OBJ_DIR)/main.o \
		$(OBJ_DIR)/play01Templates.o \
		$(OBJ_DIR)/playground.o


# Build
## linking
$(TARGET): $(OBJECTS)
# TODO: mkdir is not working somehow :(
#	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

## compiling
$(OBJ_DIR)/%.o: %.cpp
#	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $^

# Rule to clean the project by removing object files and the executable
clean:
ifeq ($(OS),Windows_NT)
	del /Q "$(OBJ_DIR)\*.o"
	del /Q "$(TARGET)"
else
	rm -f $(OBJ_DIR)/*.o
	rm -f $(TARGET)
endif
