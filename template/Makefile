#
# ogolny makefile do kompilowania programow
#

IDIR	= ./include
SDIR 	= ./src
ODIR 	= ./obj
EDIR 	= ./exe
LDIR 	= ./lib

LIBS	= -lm

RM 	    = rm -f

CXX 	= g++
CXXFLAGS= -std=c++17 -pedantic -Wall -Wextra -Werror -fstack-protector-strong -g -I${IDIR}

_DEPS 	= competitive.h
DEPS 	= $(patsubst %,$(IDIR)/%,$(_DEPS))

_PRG 	= main.cpp
PRG     = $(wildcard ${SDIR}/*.cpp)

_OBJ 	= main.o
OBJ 	= $(patsubst %,$(ODIR)/%,$(_OBJ))

_EXE	= main
EXE     = $(patsubst ${SDIR}/%.cpp,${EDIR}/%,$(PRG))

.PHONY: all clean

all: $(EXE)

showobjects:
	@echo ${DEPS}
	@echo ${PRG}
	@echo ${OBJ}
	@echo ${EXE}

main: main.o
	$(CXX) -o ${EDIR}/$@ $^ $(CXXFLAGS)

main.o: ./src/main.cpp ./include/competitive.h
	$(CC) -c -o $@ $< $(CXXFLAGS)

mrproper: clean

clean:
	$(RM) ${EDIR}/* ${ODIR}/*.o ${SDIR}/*~
