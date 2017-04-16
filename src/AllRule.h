#ifndef IDS_ALLRULE_H
#define IDS_ALLRULE_H

#include <string>
#include <vector>
#include "Rule.h"
#include "Packet.h"

/* Rule that applies only if *all* the keywords are in the packet's content */
class AllRule : public Rule {
public:
    AllRule(unsigned long src, unsigned long dest,
            unsigned long threshold, std::vector<std::string> &words);

    bool check(const Packet packet);
    ~AllRule();
};

#endif //IDS_ALLRULE_H
