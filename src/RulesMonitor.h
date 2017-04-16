#ifndef IDS_RULESMONITOR_H
#define IDS_RULESMONITOR_H


#include <mutex>
#include <vector>
#include "Rule.h"

class RulesMonitor {
    std::mutex m;
    std::vector<Rule*> rules;
public:
    explicit RulesMonitor(std::vector<Rule*> rules);
    explicit RulesMonitor(RulesMonitor&& other);
    bool check(Packet& p);
    unsigned long rules_size();
};


#endif //IDS_RULESMONITOR_H
