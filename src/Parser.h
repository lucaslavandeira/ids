#ifndef IDS_PARSER_H
#define IDS_PARSER_H

#include <fstream>
#include <vector>
#include "Packet.h"

/* Parser of packet capture files. See assignment for the specified format.
 * Serves as a wrapper for the file parsing implementation */
class Parser {
public:
    explicit Parser(const char *file);
    explicit Parser(Parser&& other);
    Packet parse_next(); // Returns the next packet in the file
    int eof();
    ~Parser();
private:
    std::fstream f;
};

#endif //IDS_PARSER_H
