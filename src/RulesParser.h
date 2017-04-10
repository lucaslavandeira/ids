#ifndef IDS_RULESPARSER_H
#define IDS_RULESPARSER_H

#include "Rules.h"
class RulesParser {
    Rules rules;
public:
    explicit RulesParser(const char* file);
    Rules getRules();
};


#endif //IDS_RULESPARSER_H
