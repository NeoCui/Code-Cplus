#Makefile for c++

CC = g++

CFLAGS = -Wall -g

#include for head file directory, and lib for library directory
#INCLUDE = -I/usr/include/
#LIB = -L/usr/lib/

EXEC = server
SRC = MyMain.cpp
OBJ = MyMain.o

$(EXEC): $(OBJ)
	@echo "Link $(OBJ) to $(EXEC) begin..."
	$(CC) $(CFLAGS) $(INCLUDE) $(LIB) -o $@ $<
	@echo "Link $(OBJ) to $(EXEC) finish."

$(OBJ): $(SRC)
	@echo "Compile $(OBJ) begin..."
	$(CC) $(CFLAGS) -c $<
	@echo "Compile $(OBJ) finish."

.PHONY: clean
clean:
	@echo "Removing linked and compiled files..."
	rm -f $(OBJ)
