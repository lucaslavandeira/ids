#ifndef IDS_FRAGMENTASEMBLER_H
#define IDS_FRAGMENTASEMBLER_H

#include <vector>
#include "Fragment.h"

class FragmentAssembler {
public:
    explicit FragmentAssembler(std::vector<Fragment> frags, int identifer);
};

#endif //IDS_FRAGMENTASEMBLER_H


