#ifndef IDS_ALWAYSRUEL_H
#define IDS_ALWAYSRUEL_H

#include <string>
#include <vector>
#include "Rule.h"

/* Rule that always applies if the packet's source-destination match, regardless
 * of content */
class AlwaysRule: public Rule {
public:
    AlwaysRule(unsigned long src, unsigned long dest,
               unsigned long threshold, std::vector<std::string> &words);

    bool check(const Packet packet);
    ~AlwaysRule();
};


#endif //IDS_ALWAYSRUEL_H
