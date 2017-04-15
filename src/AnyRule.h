#ifndef IDS_ANYRULE_H
#define IDS_ANYRULE_H

#include <string>
#include <vector>
#include "Rule.h"

class AnyRule : public Rule {
public:
    AnyRule(unsigned long src, unsigned long dest,
         unsigned long threshold, std::vector<std::string> words);

    bool check(const Fragment f);
    ~AnyRule();
};


#endif //IDS_ANYRULE_H
