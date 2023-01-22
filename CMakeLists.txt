cmake_minimum_required(VERSION 3.21)
project(07_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project
        test/main.cpp
        include/Hasher.h
        src/Hasher.cpp
        src/BloomFilter.cpp
        include/BloomFilter.h
        test/BloomFilterUsernames.cpp)
