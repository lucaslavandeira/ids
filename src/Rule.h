#ifndef IDS_RULES_H
#define IDS_RULES_H

#include <string>
#include <vector>
#include "Packet.h"

/* "Abstract" source class for the other rules. Counts matches of strings with
 * specified keywords and source-dest tuples. Has a threshold of allowed counts
 * before the IDS system starts to emit alerts */
class Rule {
protected:
    unsigned long src;
    unsigned long dest;
    unsigned long threshold;
    unsigned long count;
    std::vector<std::string> words;

    // Checks for addresses match with packet
    bool check_addresses(const Packet packet);

    bool over_threshold(); // true if count >= threshold
public:
    Rule(unsigned long src, unsigned long dest,
         unsigned long threshold, std::vector<std::string>& words);

    virtual ~Rule();

    /* Checks if the packet matches the rule. Returns true if an alert
     * should be emitted (when the matches count is over threshold) */
    virtual bool check(const Packet fragment) = 0;
};

#endif //IDS_RULES_H
