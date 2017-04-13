#include <iostream>
#include "FragmentAssembler.h"


FragmentAssembler::FragmentAssembler(std::vector<Fragment> frags,
                                     int identifier) {
    for (unsigned long i = 0; i < frags.size(); i++) {
        std::cout << frags.at(i).get_message() << std::endl;
    }
}

