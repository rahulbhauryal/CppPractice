CC := g++
CFLAGS := -std=c++17 -Wall -Wextra -pthread -I../lib/googletest/googletest/include
LDFLAGS := -L../lib/googletest/build/lib
LDLIBS := -lgtest -lgtest_main

# Directory structure
SRCDIR := src
TESTDIR := test
BUILDDIR := build
TARGET := test_main

# Source files
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
TEST_SOURCES := $(wildcard $(TESTDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
TEST_OBJECTS := $(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%.o,$(TEST_SOURCES))

# Build targets
all: $(TARGET)

$(TARGET): $(OBJECTS) $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(TEST_OBJECTS) $(LDFLAGS) $(LDLIBS) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
#	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
#	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: all clean
