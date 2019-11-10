CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g
LBLIBS = -pthread

SRC = webcrawler.cc
OBJ = $(SRC:.cc=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)