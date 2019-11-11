CXX = g++
CXXFLAGS = -g -Wall -Wextra -pedantic -fsanitize=address -fno-omit-frame-pointer -fsanitize=leak
LBLIBS = -pthread

SRC = webcrawler.cc
OBJ = $(SRC:.cc=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)