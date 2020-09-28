# Usage:
# $ make problem

CC = g++
CFLAGS = -g -pedantic -Wextra -Wall -Werror -Wshadow -fstack-protector-strong -std=c++17

.PHONY: all clean

all: temp

%: %.cpp
	$(CC) -o $@ $< $(CFLAGS)

clean: 
	rm -f temp *.o
