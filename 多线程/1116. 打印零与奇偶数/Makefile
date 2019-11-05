CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g
LBLIBS = -pthread
SRC = printf_zero_even_odd.cc
OBJ = $(SRC:.cc=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)