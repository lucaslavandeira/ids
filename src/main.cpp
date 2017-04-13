#include <iostream>
#include <fstream>
#include <cstring>
#include "Parser.h"
#include "RulesParser.h"
#include "FragmentAssembler.h"


void file_parse(char* path) {
    Parser p(path);
    while (!p.eof()) {
        Fragment frag = p.parse_next();
        std::cout << frag.get_message() << std::endl;
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "ERROR: Invalid arguments\n"
                       "Usage: ./tp <cfg file> <src files> ..." << std::endl;
        return 1;
    }

    RulesParser b(argv[1]);

    std::vector<Fragment> frags;
    for (int i = 2; i < argc; i++) {
        file_parse(argv[i]);
    }

    FragmentAssembler assembler(frags, 0);
    return 0;
}

