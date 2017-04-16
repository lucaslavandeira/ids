#ifndef IDS_RULESPARSER_H
#define IDS_RULESPARSER_H


#include <vector>
#include <string>
#include "Rule.h"

class RulesParser {
    std::fstream f;
    std::vector<Rule*> rules;
public:
    explicit RulesParser(const char* file);
    ~RulesParser();
    std::vector<Rule*>* get_rules();

private:
    // Creates rule object from the string s, formatted as per the assigment
    void parse_rule(std::string s);
};


#endif //IDS_RULESPARSER_H
