#ifndef IDS_RULES_H
#define IDS_RULES_H

#include <string>
#include <vector>
#include "Fragment.h"

class Rule {
    unsigned long src;
    unsigned long dest;
    unsigned long threshold;
protected:
    unsigned long count;
    std::vector<std::string> words;
    bool check_addresses(const Fragment fragment);
public:
    Rule(unsigned long src, unsigned long dest,
         unsigned long threshold, std::vector<std::string> words);

    virtual void check(const Fragment fragment) = 0;
    bool over_threshold();
    virtual ~Rule();
};

#endif //IDS_RULES_H
