# the compiler: gcc for C program, define as g++ for C++
CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS  = -g -Wall -Wextra -O2 -std=c++17

# the build target executable:
TARGET = main

all: $(TARGET)

$(TARGET): ../src/$(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) ../src/$(TARGET).cpp

clean:
	$(RM) $(TARGET)
