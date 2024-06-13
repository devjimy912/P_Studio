CC = g++
SRC = arraytotree.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.cpp %.h
	$(CC) -c $<

clean:
	del $(OBJ) arraytotree.exe
