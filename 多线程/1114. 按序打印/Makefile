CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g
LBLIBS = -pthread

SRC = print.cc
OBJ = $(SRC:.cc=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)