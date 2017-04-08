#include <iostream>
#include <cstdio>
#include "Parser.h"


Parser::Parser(const char *file, const char *flags) {
    f = fopen(file, flags);
    result = "Jeje";
    parse();
}

void Parser::parse() {
    std::cout << f << std::endl;
    return;
}

Parser::~Parser() {
    fclose(f);
}
