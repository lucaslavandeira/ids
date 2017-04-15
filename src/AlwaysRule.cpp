#include "AlwaysRule.h"

AlwaysRule::AlwaysRule(unsigned long src, unsigned long dest,
                       unsigned long threshold,
                       std::vector<std::string> words) :
        Rule(src, dest, threshold, words)
{
}


bool AlwaysRule::check(const Fragment f) {
    if (!f.has_addresses(src, dest)) {
        return false;
    }

    count++;

    return over_threshold();
}

AlwaysRule::~AlwaysRule() {
}
