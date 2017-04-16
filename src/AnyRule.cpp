#include "AnyRule.h"

AnyRule::AnyRule(unsigned long src, unsigned long dest, unsigned long threshold,
                 std::vector<std::string>& words) :
        Rule(src, dest, threshold, words)
{
}

bool AnyRule::check(const Packet packet) {
    if (!check_addresses(packet)) {
        return false;
    }

    for (std::string word : words) {
        if (packet.get_message().find(word) != std::string::npos) {
            count++;
            return over_threshold();
        }
    }

    return false;
}

AnyRule::~AnyRule() {
}
