#ifndef IDS_FRAGMENTASEMBLER_H
#define IDS_FRAGMENTASEMBLER_H

#include <vector>
#include "Fragment.h"

class FragmentAssembler {
public:
    FragmentAssembler();
    void add_fragment(Fragment f);
    void print_frags();
private:
    std::vector<Fragment> frags;
    std::vector<Fragment> packets;
    void assemble();
};

#endif //IDS_FRAGMENTASEMBLER_H


