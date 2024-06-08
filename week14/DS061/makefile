CC = g++
SRC = LLQueue.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

%.o: %.cpp %.h
	$(CC) -c $<

clean:
	del $(OBJ) main.exe
