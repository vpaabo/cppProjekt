CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

SRC = $(wildcard src/*.cpp)
INCL = $(wildcard include/*.h)
# Makefile juures tohib olla ainult üks .cpp fail (ehk main)
MAIN = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)
RM = $(OBJ)
EXEC = main.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(RM) $(EXEC)
