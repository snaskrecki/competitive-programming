CC = g++
CFLAGS = -g -pedantic -Wextra -Wall -Werror -Wshadow -fstack-protector-strong -std=c++17

all: main

%: %.cpp
	$(CC) -o $@ $< $(CFLAGS)

clean: 
	rm -f main
