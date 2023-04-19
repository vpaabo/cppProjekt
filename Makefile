CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
SRC = test.cpp
OBJ = $(SRC:.cpp=.o)
RM = test.o
EXEC = test.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(RM) $(EXEC)
