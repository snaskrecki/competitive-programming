# Usage:
# $ make problem

CC = g++
TIGHT = -g -pedantic -Wextra -Wall -Werror -Wshadow -fstack-protector-strong -std=c++17
LOOSE = -g -pedantic -Wextra -Wall -Wshadow -fstack-protector-strong -std=c++17
CFLAGS = $(LOOSE)

.PHONY: all clean

all: main

%: %.cpp
	$(CC) -o $@ $< $(CFLAGS)
	mkdir -p results

clean: 
	rm -f *.o
	rm -f main
	rm -rf results
