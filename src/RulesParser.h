#ifndef IDS_RULESPARSER_H
#define IDS_RULESPARSER_H

#include "Rules.h"

class RulesParser {
    std::fstream f;
    Rules rules;
public:
    explicit RulesParser(const char* file);
    void getRules();
};


#endif //IDS_RULESPARSER_H
