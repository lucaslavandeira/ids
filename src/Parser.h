#ifndef IDS_PARSER_H
#define IDS_PARSER_H

#include <fstream>
using std::fstream;
class Parser {
private:
    fstream f;
    unsigned int message_len;
    unsigned int identifier;
    bool MF;
    unsigned int offset;
    unsigned long dest;
    unsigned long source;
    long data_len;
    char *data;
public:
    explicit Parser(const char *file);
    void parse();
    ~Parser();
};


#endif //IDS_PARSER_H
