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


void FragmentAssembler::assemble() {
    std::vector<Fragment> assembly_line;
    for (long unsigned i = 0; i < frags.size(); i++) {
        Fragment f = frags.at(i);
        if (f.is_full_packet()) {
            assembly_line.push_back(f);
            break;
        }

        if(i == frags.size() -1) {
            continue;
        }
        if (f.precedes(frags.at(i+1)) || assembly_line.back().precedes(f)) {
            assembly_line.push_back(f);
        }
    }

    if(assembly_line.size()) {
        Fragment packet(assembly_line);
        if (!assembly_line.back().more_fragments()){
            packets.push_back(packet);
        }
    }
}

const std::vector<Fragment> *FragmentAssembler::get_packets() const {
    return &packets;
}
