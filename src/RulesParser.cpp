#include <fstream>
#include <iostream>
#include <cstdlib>

#include "RulesParser.h"
#include "AnyRule.h"
#include "AllRule.h"
#include "AlwaysRule.h"

// Upper limit for rule length. Can be modified if we need to check more words
#define kMaxRuleLength 256
#define DELIM " \n"
#define RULE_END ';'

#define SRC 0
#define DEST 1
#define THRES 2
#define KEYWORD 3

using std::fstream;
using iter = std::vector<std::string>::iterator;


RulesParser::RulesParser(const char *file) : f(fstream(file, fstream::in)) {
    if (!f.is_open()) {
        std::cout << "Error parsing rules file: " << file << std::endl;
        return;
    }

    std::vector<Rule> rules;
    // Read from file and parse rules up to RULE_END character.
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

    // Finds rule parameters, ignoring whitespaces and newlines
    while (end != s.size() - 1) {
        start = s.find_first_not_of(DELIM, end);
        end = s.find_first_of(DELIM, start);
        std::string param(s, start, end-start);
        params.push_back(param);
    }

    // First param: source, second: destination, third: threshold
    char* result;
    unsigned long src = std::strtoul(params.at(SRC).c_str(), &result, 10);
    unsigned long dest = std::strtoul(params.at(DEST).c_str(), &result, 10);
    unsigned long threshold = std::strtoul(params.at(THRES).c_str(),
                                           &result, 10);

    // Fourth param: rule keyword (implemented as different classes)
    std::string keyword = *(params.begin() + KEYWORD);

    // Rest of the parameters are the words to check for
    params = std::vector<std::string>(params.begin() + KEYWORD + 1,
                                      params.end());

    Rule* rule;
    if (keyword == "any") {
        rule = new AnyRule(src, dest, threshold, params);
    } else if (keyword == "always") {
        rule = new AlwaysRule(src, dest, threshold, params);
    } else if (keyword == "all") {
        rule = new AllRule(src, dest, threshold, params);
    } else {
        return;
    }
    rules.push_back(rule);
}

std::vector<Rule*>* RulesParser::get_rules() {
    return &rules;
}

RulesParser::~RulesParser() {
    for (Rule* rule: rules) {
        delete rule;
    }
}
