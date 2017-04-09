#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "Parser.h"

#define HEADER_SIZE 20


Parser::Parser(const char *file) : f(fstream(file, fstream::in)) {
    if (!f.is_open()) {
        std::cout << file << std::endl;
        return;
    }

    parse();
}

unsigned int return_big_endian(char* src, int start, int stop) {
    /* Parses array src from start to stop (non inclusive) and returns the
     * big endian number from that slice numerical byte values
     * (that is, most significant byte first)
     */
    unsigned int result = 0;
    int len = stop - start;
    for (int i = 0; i < len; i++) {
        result += (+src[start + i] >> (8 * (len - i - 1)));
    }
    return result;
}

void Parser::parse() {
    /* Parsing for IP packets. Many fields are ignored.
     * Consult assignment PDF for the fields format
     */

    // Fetch header data
    char header[HEADER_SIZE] = "";
    f.read(header, HEADER_SIZE);

    // Bytes 2 and 3: message length
    unsigned int message_len = return_big_endian(header, 2, 4);

    // Bytes 4 and 5: identifier
    unsigned int identifier = return_big_endian(header, 4, 6);


    // Third bit from byte 6: MF flag
    char mask = 0x10;
    bool MF = (mask & header[6]) != 0;

    // Last 5 bytes from byte 6 + byte 7: offset
    // Mask the last 5 bytes from byte 6
    mask = 0x1f;  // 0001 1111
    unsigned int offset = 0;
    offset += (mask & header[6]) << 8;
    offset += header[7];


    // Bytes 12 - 15: source IP, 16-19: dest IP
    unsigned long source = return_big_endian(header, 12, 16);
    unsigned long dest = return_big_endian(header, 16, 20);

    // Byte 20 onwards: packet data
    f.seekg(0, f.end);
    long data_len = f.tellg();
    data_len -= 20;
    f.seekg(HEADER_SIZE, f.beg);

    char* data = (char*) malloc((size_t) data_len + 1);
    memset(data, 0 , (size_t) data_len + 1); // Fix valgrind warning
    f.read(data, data_len);
    std::string a(data);
    free(data);

    // Create fragment with all the collected data
    Fragment frag(message_len, identifier, MF, offset, source, dest, a);
    fragments.push_back(frag);
}


std::vector<Fragment> Parser::get_fragments() {
    return fragments;
}

Parser::~Parser() {
}
