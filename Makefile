# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

# Directories
SRCDIR = src
OBJDIR = obj
INCDIR = include
LIBDIR = lib
BINDIR = bin
TESTDIR = tests

# Files
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
INC = $(wildcard $(INCDIR)/*.h)
LIB = $(wildcard $(LIBDIR)/*.a)

# Executable
TARGET = $(BINDIR)/myprogram

# Build rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LIB) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Test rules
test: $(TESTDIR)/test

$(TESTDIR)/test: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LIB) $(TESTDIR)/test.cpp -o $(TESTDIR)/test

# Cleanup rules
clean:
	rm -f $(OBJDIR)/*.o $(TARGET) $(TESTDIR)/test