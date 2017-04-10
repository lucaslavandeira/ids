#include <iostream>
#include <fstream>
#include <cstring>
#include "Parser.h"
#include "RulesParser.h"
#include "FragmentAssembler.h"

using std::cerr;
using std::endl;
int main(int argc, char** argv) {
    if (argc < 3) {
        cerr << "ERROR: Invalid arguments\n"
                       "Usage: ./tp <cfg file> <src files> ..." << endl;
        return 1;
    }

    RulesParser b(argv[1]);

    std::vector<Fragment> frags;
    for (int i = 2; i < argc; i++) {
        Parser p(argv[i]);
        std::vector<Fragment> p_frags = p.get_fragments();
        frags.insert(frags.end(), p_frags.begin(), p_frags.end());
    }

    FragmentAssembler assembler(frags);
    return 0;
}
