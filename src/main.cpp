#include <iostream>
#include <algorithm>
#include <map>
#include "Parser.h"
#include "RulesParser.h"
#include "FragmentAssembler.h"


void file_parse(char* path, FragmentAssembler assembler,
                std::vector<Rule*> &rules) {
    std::vector<Fragment> frags;
    Parser p(path);
    while (!p.eof()) {
        Fragment f = p.parse_next();
        frags.push_back(f);
        for (auto i = rules.begin(); i != rules.end(); i++) {
            (*i)->check(f);
        }
    }

    for (auto i = rules.begin(); i != rules.end(); i++) {
    }


}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "ERROR: Invalid arguments\n"
                       "Usage: ./tp <cfg file> <src files> ..." << std::endl;
        return 1;
    }

    RulesParser rules_parser(argv[1]);
    std::vector<Rule*>* rules = rules_parser.get_rules();
    FragmentAssembler assembler;
    for (int i = 2; i < argc; i++) {
        file_parse(argv[i], assembler, *rules);
    }

    return 0;
}

