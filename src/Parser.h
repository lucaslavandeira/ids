#ifndef IDS_PARSER_H
#define IDS_PARSER_H

#include <fstream>
#include <vector>
#include "Packet.h"


class Parser {
public:
    explicit Parser(const char *file);
    explicit Parser(Parser&& other);
    Packet parse_next();
    int eof();
    ~Parser();
private:
    std::fstream f;
};

#endif //IDS_PARSER_H
