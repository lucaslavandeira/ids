#include <iostream>
#include "Parser.h"
#include "RulesParser.h"
#include "FragmentAssembler.h"

void print_alert(Fragment f, unsigned long index) {
    std::cout << "Rule " << index <<": ALERT! " <<
              std::hex << f.get_source() << " -> " <<
              std::hex << f.get_dest() << ":";

    for(unsigned long j = 0; j < (f.get_message().size()); j++) {
        std::cout <<  " " << std::hex << +f.get_message().at(j);
    }
    std::cout << std::endl;
}

void file_parse(char* path, FragmentAssembler* assembler,
                std::vector<Rule*> &rules) {

    Parser p(path);
    while (!p.eof()) {
        Fragment f = p.parse_next();
        assembler->add_fragment(f);
    }

    const std::vector<Fragment> packets = *assembler->get_packets();

    for(Fragment f : packets) {
        for (long unsigned i = 0; i < rules.size(); i++) {
            if (rules.at(i)->check(f)) {
                print_alert(f, i);
            }
        }
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
        file_parse(argv[i], &assembler, *rules);
    }

    return 0;
}

