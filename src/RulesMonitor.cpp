#include <iostream>
#include "RulesMonitor.h"
#include "Lock.h"

RulesMonitor::RulesMonitor(std::vector<Rule*> rules) :
    rules(rules)
{
}

// Prints the formatted alert message
void print(Packet &p, unsigned long rule_index) {
    std::cout << "Rule " << rule_index <<": ALERT! " <<
              std::hex << p.get_source() << " -> " <<
              std::hex << p.get_dest() << ":";

    std::string message = p.get_message();
    for (unsigned long j = 0; j < (message.size()); j++) {
        std::cout <<  " " << std::hex << +message.at(j);
    }
    std::cout << std::endl;
}

bool RulesMonitor::check_and_print(Packet &p) {
    Lock lock(m);
    for (long unsigned i = 0; i < rules.size(); i++) {
        if (rules.at(i)->check(p)) {
            print(p, i);
        }
    }
    return false;
}

RulesMonitor::RulesMonitor(RulesMonitor &&other) {
    this->rules = other.rules;
}
