#include <iostream>
#include "Parser.h"
#include "RulesParser.h"
#include "FragmentAssembler.h"


void print_alert(Packet f, unsigned long rule_index) {
    std::cout << "Rule " << rule_index <<": ALERT! " <<
              std::hex << f.get_source() << " -> " <<
              std::hex << f.get_dest() << ":";

    std::string message = f.get_message();
    for (unsigned long j = 0; j < (message.size()); j++) {
        std::cout <<  " " << std::hex << +message.at(j);
    }
    std::cout << std::endl;
}

void file_parse(char* path, FragmentAssembler* assembler,
                std::vector<Rule*> &rules) {
    Parser parser(path);
    while (!parser.eof()) {
        Packet f = parser.parse_next();
        assembler->add_fragment(f);
    }

    const std::vector<Packet> packets = *assembler->get_packets();

    for (Packet p : packets) {
        for (long unsigned i = 0; i < rules.size(); i++) {
            if (rules.at(i)->check(p)) {
                print_alert(p, i);
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
    std::vector<Rule*> rules = *rules_parser.get_rules();
    FragmentAssembler assembler;

    for (int i = 2; i < argc; i++) {
        file_parse(argv[i], &assembler, rules);
    }

    return 0;
}

