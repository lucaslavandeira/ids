#include "AlwaysRule.h"

AlwaysRule::AlwaysRule(unsigned long src, unsigned long dest,
                       unsigned long threshold,
                       std::vector<std::string> &words) :
        Rule(src, dest, threshold, words)
{
}


bool AlwaysRule::check(const Packet packet) {
    if (!check_addresses(packet)) {
        return false;
    }

    count++;

    return over_threshold();
}

AlwaysRule::~AlwaysRule() {
}
