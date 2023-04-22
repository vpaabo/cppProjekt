CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
SRC = func.h func.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
RM = func.o main.o
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
