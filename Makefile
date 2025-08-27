CC=gcc
CFLAGS=-Wall -g
BIN=bin/log_pipeline
SRC=$(wildcard src/*.c)

all:
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

clean:
	rm -rf bin
