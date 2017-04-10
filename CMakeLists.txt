cmake_minimum_required(VERSION 3.6)
project(ids)

set(CMAKE_C++_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Packet.cpp src/Parser.cpp src/Fragment.cpp
        src/Rules.cpp src/RulesParser.cpp src/FragmentAssembler.cpp)
add_executable(ids ${SOURCE_FILES})