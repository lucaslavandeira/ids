#ifndef IDS_PARSER_H
#define IDS_PARSER_H


class Parser {
private:
    FILE* f;
    const char *result;
public:
    Parser(const char* file, const char* flags);
    void parse();
    ~Parser();
};


#endif //IDS_PARSER_H
