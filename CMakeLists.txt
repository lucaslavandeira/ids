cmake_minimum_required(VERSION 3.7)
project(ids)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/AllRule.cpp
        src/AllRule.h
        src/AlwaysRule.cpp
        src/AlwaysRule.h
        src/AnyRule.cpp
        src/AnyRule.h
        src/FragmentAssembler.cpp
        src/FragmentAssembler.h
        src/Lock.cpp
        src/Lock.h
        src/main.cpp
        src/Packet.cpp
        src/Packet.h
        src/Parser.cpp
        src/Parser.h
        src/Rule.cpp
        src/Rule.h
        src/RulesParser.cpp
        src/RulesParser.h
        src/Thread.cpp
        src/Thread.h src/AssemblerMonitor.cpp src/AssemblerMonitor.h src/RulesMonitor.cpp src/RulesMonitor.h src/IDSThread.cpp src/IDSThread.h src/AlertPrinter.cpp src/AlertPrinter.h)

add_executable(ids ${SOURCE_FILES})