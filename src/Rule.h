#ifndef IDS_RULES_H
#define IDS_RULES_H

#include <string>
#include <vector>
#include "Fragment.h"

class Rule {
protected:
    unsigned long src;
    unsigned long dest;
    unsigned long threshold;
    unsigned long count;
    std::vector<std::string> words;
    bool check_addresses(const Fragment fragment);
    bool over_threshold();
public:
    Rule(unsigned long src, unsigned long dest,
         unsigned long threshold, std::vector<std::string> words);

    virtual bool check(const Fragment fragment) = 0;

    virtual ~Rule();
};

#endif //IDS_RULES_H
