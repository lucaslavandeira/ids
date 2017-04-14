#include <fstream>
#include <iostream>
#include <cstdlib>

#include "RulesParser.h"
#define kMaxRuleLength 256
#define DELIM " \n"
#define RULE_END ';'

#define SRC 0
#define DEST 1
#define THRES 2

using std::fstream;
using iter = std::vector<std::string>::iterator;


RulesParser::RulesParser(const char *file) : f(fstream(file, fstream::in)) {
    if (!f.is_open()) {
        std::cout << "Error parsing rules file: " << file << std::endl;
        return;
    }

    std::vector<Rule> rules;

    char buf[kMaxRuleLength];

    while (true) {
        f.getline(buf, kMaxRuleLength, RULE_END);
        if (f.eof()) {
            return;
        }
        parse_rule(std::string(buf));
    }
}


void RulesParser::parse_rule(std::string s) {
    unsigned long start, end = 0;
    std::vector<std::string> params;

    while (end != s.size() - 1) {
        start = s.find_first_not_of(DELIM, end);
        end = s.find_first_of(DELIM, start);
        std::string param(s, start, end-start);
        params.push_back(param);
    }

    char* result;
    unsigned long src = std::strtoul(params.at(SRC).c_str(), &result, 10);
    unsigned long dest = std::strtoul(params.at(DEST).c_str(), &result, 10);
    unsigned long threshold = std::strtoul(params.at(THRES).c_str(),
                                           &result, 10);

    for (iter it = params.begin() + 4; it != params.end(); it++) {
        std::cout << *it << std::endl;
    }
    rules.push_back(Rule(src, dest, threshold, params));
}

const std::vector<Rule>* RulesParser::get_rules() const {
    return &rules;
}


