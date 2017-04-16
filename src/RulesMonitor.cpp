#include <iostream>
#include "RulesMonitor.h"
#include "Lock.h"

RulesMonitor::RulesMonitor(std::vector<Rule*> rules) :
    rules(rules)
{
}

bool RulesMonitor::check(Packet &p) {
    Lock lock(m);
    for (long unsigned i = 0; i < rules.size(); i++) {
        if (rules.at(i)->check(p)) {
            return true;
        }
    }
    return false;
}

unsigned long RulesMonitor::rules_size() {
    return rules.size();
}

RulesMonitor::RulesMonitor(RulesMonitor &&other) {
    this->rules = other.rules;
}

