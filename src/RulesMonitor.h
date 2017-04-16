#ifndef IDS_RULESMONITOR_H
#define IDS_RULESMONITOR_H


#include <mutex>
#include <vector>
#include "Rule.h"


/* Monitor for the Rules vector and the alert emission. */
class RulesMonitor {
    std::mutex m;
    std::vector<Rule*> rules;
public:
    explicit RulesMonitor(std::vector<Rule*> rules);
    explicit RulesMonitor(RulesMonitor&& other);
    bool check_and_print(Packet &p);
};


#endif //IDS_RULESMONITOR_H
