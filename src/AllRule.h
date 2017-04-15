#ifndef IDS_ALLRULE_H
#define IDS_ALLRULE_H

#include <string>
#include <vector>
#include "Rule.h"

class AllRule : public Rule {
public:
    AllRule(unsigned long src, unsigned long dest,
         unsigned long threshold, std::vector<std::string> words);

    void check(const Fragment fragment);
};

#endif //IDS_ALLRULE_H
