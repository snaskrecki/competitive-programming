cmake_minimum_required(VERSION 3.10)
project(ProjectName)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-g -W -Wall -Wextra -Wshadow -std=c++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #Vim (YCM)

add_executable(main src/main.cpp)
