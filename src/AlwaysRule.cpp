#include "AlwaysRule.h"

AlwaysRule::AlwaysRule(unsigned long src, unsigned long dest,
                       unsigned long threshold,
                       std::vector<std::string> words) :
        Rule(src, dest, threshold, words)
{
}


void AlwaysRule::check(const Fragment fragment) {
    count++;
}