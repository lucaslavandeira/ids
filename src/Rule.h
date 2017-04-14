#ifndef IDS_RULES_H
#define IDS_RULES_H

#include <string>
#include <vector>

class Rule {
    unsigned long src;
    unsigned long dest;
    unsigned long threshold;
    std::vector<std::string> words;
public:
    Rule(unsigned long src, unsigned long dest,
         unsigned long threshold, std::vector<std::string> words);
};


#endif //IDS_RULES_H
