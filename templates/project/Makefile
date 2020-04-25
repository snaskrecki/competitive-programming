#
# ogolny makefile do kompilowania programow
#
CXX 	= g++
RM 		= rm -f
GCC_OPT = -std=c++17 -pedantic -Wall -Wextra -Werror -fstack-protector-strong -g

PRG_CXX = $(wildcard *.cpp) 
PRG     = $(PRG_CXX)

EXE_CXX = $(patsubst %.cpp,%,$(PRG_CXX))
EXE     = $(EXE_CXX)

all: $(EXE)

%: %.cpp
	$(CXX) $(GCC_OPT) $^ -o $*

mrproper: clean

clean:
	$(RM) $(EXE) *.o *~
