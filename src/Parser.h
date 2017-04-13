#ifndef IDS_PARSER_H
#define IDS_PARSER_H

#include <fstream>
#include <vector>
#include "Fragment.h"

using std::fstream;

class Parser {
public:
    explicit Parser(const char *file);
    Fragment parse_next();
    std::vector<Fragment> get_fragments();
    int eof();
    ~Parser();
private:
    fstream f;
    std::vector<Fragment> fragments;
};

#endif //IDS_PARSER_H
