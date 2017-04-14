#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "RulesParser.h"

#define kMaxRuleLength 256
#define DELIM " \n"
#define NUMERICAL_VALUES 3
using std::fstream;


RulesParser::RulesParser(const char *file) : f(fstream(file, fstream::in)) {
    if (!f.is_open()) {
        std::cout << "Error parsing rules file: " << file << std::endl;
        return;
    }
    getRules();
}


void parse_rule(std::string s) {
    unsigned long start, end = 0;
    std::vector<std::string> params;

    for (int i = 0; i < NUMERICAL_VALUES; i++) {
        start = s.find_first_not_of(DELIM, end);
        end = s.find_first_of(DELIM, start);
        std::string param(s, start, end);
        params.push_back(param);
        std::cout << param << std::endl;
    }
}

void RulesParser::getRules() {
    char buf[kMaxRuleLength];
    f.getline(buf, kMaxRuleLength, ';');

    parse_rule(std::string(buf));
    if (f.eof()) {
        return;
    }
}


