#include <iostream>
#include <algorithm>
#include "FragmentAssembler.h"

using iter = std::vector<Fragment>::iterator;

FragmentAssembler::FragmentAssembler() {
    std::vector<Fragment> frags;
}

void FragmentAssembler::add_fragment(Fragment f) {
    frags.push_back(f);
    std::sort(frags.begin(), frags.end(), Fragment::compare);
    assemble();
}

void FragmentAssembler::print_frags() {
    for (unsigned long i = 0; i < frags.size(); ++i) {
        std::cout << frags.at(i).get_message() << std::endl;
    }
}

void FragmentAssembler::assemble() {
    std::vector<Fragment> assembly_line;
    for (iter it = frags.begin(); it != frags.end(); it++) {
        if (it->more_fragments()) {
            assembly_line.push_back(*(it));
            packets.push_back(Fragment(assembly_line));
        }

        if (it + 1 == frags.end()) {
            continue;
        }

        if (it->precedes(*(it + 1))) {
            assembly_line.push_back(*(it));
        } else {
            assembly_line.empty();
        }
    }
}
