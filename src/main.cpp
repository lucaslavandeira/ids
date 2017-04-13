#include <iostream>
#include <fstream>
#include <cstring>
#include "Parser.h"
#include "RulesParser.h"
#include "FragmentAssembler.h"


void file_parse(char* path, FragmentAssembler assembler) {
    Parser p(path);
    while (!p.eof()) {
        assembler.add_fragment(p.parse_next());
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "ERROR: Invalid arguments\n"
                       "Usage: ./tp <cfg file> <src files> ..." << std::endl;
        return 1;
    }

    RulesParser b(argv[1]);

    FragmentAssembler assembler;
    for (int i = 2; i < argc; i++) {
        file_parse(argv[i], assembler);
    }

    return 0;
}

