#include "AnyRule.h"

AnyRule::AnyRule(unsigned long src, unsigned long dest, unsigned long threshold,
                 std::vector<std::string> words) :
        Rule(src, dest, threshold, words)
{
}

void AnyRule::check(const Fragment fragment) {
    count++;
}