#ifndef IDS_RULESPARSER_H
#define IDS_RULESPARSER_H


#include <vector>
#include <string>
#include "Rule.h"

class RulesParser {
    std::fstream f;
    std::vector<Rule*> rules;
public:
    ~RulesParser();
    explicit RulesParser(const char* file);
    std::vector<Rule*>* get_rules();

private:
    void parse_rule(std::string s);
};


#endif //IDS_RULESPARSER_H
