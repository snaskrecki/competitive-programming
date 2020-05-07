# Usage:
# $ make ./exe/main
# $ make clean

SHELL = /bin/bash

IDIR = ./include
SDIR = ./src
ODIR = ./obj
EDIR = ./exe
LDIR = ./lib

LIBS = -lm
INCLUDES = -I${IDIR}

RM = rm -f

CC = g++
CFLAGS = -std=c++17 -pedantic -Wall -Wextra -Werror -fstack-protector-strong -g 

_DEPS = competitive.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_SRCS = main.cpp
SRCS = $(wildcard ${SDIR}/*.cpp)

_OBJS = main.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

_EXE = main
EXE = $(patsubst ${SDIR}/%.cpp,${EDIR}/%,$(SRCS))

.PHONY: all clean

all: $(EXE)

$(EDIR)/%: $(ODIR)/%.o
	$(CC) -o $@ $^ $(CFLAGS) $(INCLUDES) $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.cpp $(IDIR)/competitive.h
	$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDES) $(LIBS)

mrproper: clean

clean:
	$(RM) ${EDIR}/* ${ODIR}/*.o ${SDIR}/*~ test/urout/*
