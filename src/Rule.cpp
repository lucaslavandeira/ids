#include <iostream>
#include "Rule.h"

Rule::Rule(unsigned long src, unsigned long dest, unsigned long threshold,
           std::vector<std::string> words)  :
        src(src),
        dest(dest),
        threshold(threshold),
        words(words) {
    count = 0;
}


bool Rule::over_threshold() {
    return count >= threshold;
}


bool Rule::check(const Fragment fragment) {
    std::cout << "this should never happen" << std::endl;
    return false;
}

bool Rule::check_addresses(const Fragment fragment) {
    return fragment.has_addresses((unsigned int) this->src,
                                  (unsigned int) this->dest);
}

Rule::~Rule() {
}
