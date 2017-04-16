#ifndef IDS_ANYRULE_H
#define IDS_ANYRULE_H

#include <string>
#include <vector>
#include "Rule.h"

// Rule that applies if *any* of the keywords are found in the packet's message
class AnyRule : public Rule {
public:
    AnyRule(unsigned long src, unsigned long dest,
         unsigned long threshold, std::vector<std::string>& words);

    bool check(const Packet packet);
    ~AnyRule();
};


#endif //IDS_ANYRULE_H
