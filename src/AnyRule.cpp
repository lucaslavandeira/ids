#include "AnyRule.h"

AnyRule::AnyRule(unsigned long src, unsigned long dest, unsigned long threshold,
                 std::vector<std::string> words) :
        Rule(src, dest, threshold, words)
{
}

bool AnyRule::check(const Fragment fragment) {
    if (!fragment.has_addresses(src, dest)) {
        return false;
    }

    for (std::string word : words) {
        if (fragment.get_message().find(word) != std::string::npos) {
            count++;
            return over_threshold();
        }
    }

    return false;
}

AnyRule::~AnyRule() {
}