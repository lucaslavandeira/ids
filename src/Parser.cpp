#include <iostream>
#include <fstream>
#include <cstdlib>
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
    message_len = return_big_endian(header, 2, 4);

    // Bytes 4 and 5: identifier
    identifier = return_big_endian(header, 4, 6);


    // Third bit from byte 6: MF flag
    char mask = 0x10;
    MF = (mask & header[6]) != 0;

    // Last 5 bytes from byte 6 + byte 7: offset
    // Mask the last 5 bytes from byte 6
    mask = 0x1f;  // 0001 1111
    offset = 0;
    offset += (mask & header[6]) << 8;
    offset += header[7];


    // Bytes 12 - 15: source IP, 16-19: dest IP
    source = return_big_endian(header, 12, 16);
    dest = return_big_endian(header, 16, 20);

    // Byte 20 onwards: packet data
    f.seekg(0, f.end);
    data_len = f.tellg();
    data_len -= 20;
    f.seekg(HEADER_SIZE, f.beg);

    data = (char*) malloc((size_t) data_len);
    f.read(data, data_len);
}

Parser::~Parser() {
    free(data);
}
