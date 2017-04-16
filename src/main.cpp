#include <iostream>
#include "Parser.h"
#include "RulesParser.h"
#include "FragmentAssembler.h"
#include "AssemblerMonitor.h"
#include "RulesMonitor.h"
#include "IDSThread.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "ERROR: Invalid arguments\n"
                "Usage: ./tp <cfg file> <src files> ..." << std::endl;
        return 1;
    }

    RulesParser rules_parser(argv[1]);
    std::vector<Rule *> rules = *rules_parser.get_rules();
    RulesMonitor r_monitor(rules);

    FragmentAssembler assembler;
    AssemblerMonitor monitor(assembler);

    std::vector<IDSThread*> threads;


    for (int i = 2; i < argc; i++) {
        threads.push_back(new IDSThread(argv[i], monitor, r_monitor));
    }

    for (Thread* t : threads) {
        t->start();
    }

    for (Thread* t : threads) {
        t->join();
    }

    return 0;
}

