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

void RulesMonitor::print(Packet &p, unsigned long rule_index) {
    Lock lock(m);

    std::cout << "Rule " << rule_index <<": ALERT! " <<
              std::hex << p.get_source() << " -> " <<
              std::hex << p.get_dest() << ":";

    std::string message = p.get_message();
    for (unsigned long j = 0; j < (message.size()); j++) {
        std::cout <<  " " << std::hex << +message.at(j);
    }
    std::cout << std::endl;
}
