CXX = g++
RM = rm -f
CXXFLAGS = -g -W -Wshadow -Wall -Wextra -std=c++17
LDFLAGS = 

PROG=main
SRCS=$(PROG).cpp
OBJS=$(SRCS:.cpp=.o)

.PHONY: all clean

all: $(PROG)

$(PROG): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	$(RM) $(PROG) $(OBJS)

