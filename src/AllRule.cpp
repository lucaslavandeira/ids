#include "AllRule.h"


AllRule::AllRule(unsigned long src, unsigned long dest, unsigned long threshold,
                       std::vector<std::string> words) :
        Rule(src, dest, threshold, words)
{
}

bool AllRule::check(const Fragment f) {
    if (!f.has_addresses(src, dest)) {
        return false;
    }

    for (std::string word : words) {
        if (f.get_message().find(word) == std::string::npos) {
            return false;
        }
    }
    count++;
    return over_threshold();
}

AllRule::~AllRule() {
}
