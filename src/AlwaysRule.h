#ifndef IDS_ALWAYSRUEL_H
#define IDS_ALWAYSRUEL_H

#include <string>
#include <vector>
#include "Rule.h"

class AlwaysRule: public Rule {
public:
    AlwaysRule(unsigned long src, unsigned long dest,
         unsigned long threshold, std::vector<std::string> words);

    bool check(const Fragment f);
    ~AlwaysRule();
};


#endif //IDS_ALWAYSRUEL_H
