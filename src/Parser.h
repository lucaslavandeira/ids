#ifndef IDS_PARSER_H
#define IDS_PARSER_H

#include <fstream>
#include <vector>
#include "Fragment.h"


class Parser {
public:
    explicit Parser(const char *file);
    Fragment parse_next();
    int eof();
    ~Parser();
private:
    std::fstream f;
};

#endif //IDS_PARSER_H
