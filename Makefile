# Makefile
CC=gcc
CFLAGS=-Iinclude -Wall -g
SRC=src/main.c src/parser.c src/executor.c src/utils.c
OBJ=$(SRC:.c=.o)
BIN=mysh

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f src/*.o $(BIN)
