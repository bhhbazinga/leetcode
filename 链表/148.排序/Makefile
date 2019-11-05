CXX = g++
CXXFLAGS = -g -Wall -Wextra -pedantic -std=c++17

SRC = linklist_quick_sort.cc
OBJ = $(SRC:.cc=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ) $(EXEC)