cmake_minimum_required(VERSION 3.6)
project(ids)

set(CMAKE_C++_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Parser.cpp src/Packet.cpp
        src/Rule.cpp src/RulesParser.cpp src/FragmentAssembler.cpp
        src/AlwaysRule.cpp src/AllRule.cpp src/AnyRule.cpp)
add_executable(ids ${SOURCE_FILES})