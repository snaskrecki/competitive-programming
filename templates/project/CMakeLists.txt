cmake_minimum_required(VERSION 3.10.0)
project(projectName)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif ()

# Nie chcemy oglądać komunikatów o procentowym postępie kompilacji.
set_property(GLOBAL PROPERTY RULE_MESSAGES OFF)

# Chcemy zobaczyć polecenia wywołane przez make.
set(CMAKE_VERBOSE_MAKEFILE ON)

# Ustawiamy wspólne opcje kompilowania dla wszystkich wariantów projektu.
# set(CMAKE_CXX_STANDARD "17")
# set(CMAKE_CXX_COMPILER "g++")
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17 -pedantic -Wall -Wextra -Werror -fstack-protector-strong -g")
set(GCC_COVERAGE_LINK_FLAGS  "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
# Domyślne opcje dla wariantów Release i Debug są sensowne.
# Jeśli to konieczne, ustawiamy tu inne.
# set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
# set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Wskazujemy pliki źródłowe.
set(SOURCE_FILES
        main.cpp)

# Wskazujemy plik wykonywalny.
add_executable(map.exe ${SOURCE_FILES})

