#include <iostream>
#include <algorithm>
#include "FragmentAssembler.h"

using iter = std::vector<Fragment>::iterator;

FragmentAssembler::FragmentAssembler() {
    std::vector<Fragment> frags;
}

void FragmentAssembler::add_fragment(Fragment f) {
    frags.push_back(f);
    assemble();
}


void FragmentAssembler::assemble() {
    std::sort(frags.begin(), frags.end(), Fragment::compare);

    std::vector<Fragment> assembly_line;
    for (long unsigned i = 0; i < frags.size(); i++) {
        Fragment f = frags.at(i);
        if (f.is_full_packet()) {
            assembly_line.push_back(f);
            break;
        }
        if (f.is_first()) {
            assembly_line.push_back(f);
            continue;
        }

        // If it's not the first and there's no packages in the line,
        // move on to the next one
        if(assembly_line.empty()) {
            continue;
        }

        // Push if they're contiguous packages
        if (assembly_line.back().precedes(f)) {
            assembly_line.push_back(f);

            // If it's the end, we already got a full package to assemble
            if (!f.more_fragments()) {
                break;
            }
        } else {
            assembly_line.clear();
        }

    }

    if(assembly_line.size()) {
        Fragment packet(assembly_line);
        if (!packet.more_fragments()) {
            packets.push_back(packet);

            // Once we create packet with the fragments, remove them from frags
            for(iter it = assembly_line.begin(); it != assembly_line.end(); it++) {
                for(iter jt = frags.begin(); jt != frags.end(); jt++) {
                    if (*it == *jt) {
                        frags.erase(jt);
                        break;
                    }
                }
            }
            assembly_line.clear();
        }


    }
}

const std::vector<Fragment> *FragmentAssembler::get_packets() const {
    return &packets;
}
