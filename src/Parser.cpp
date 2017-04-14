#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "Parser.h"

#define HEADER_SIZE 20
#define MSG_CHUNK 100
using std::fstream;

Parser::Parser(const char *file) : f(fstream(file, fstream::in)) {
    if (!f.is_open()) {
        std::cout << "Error parsing input file: " << file << std::endl;
        return;
    }
}

unsigned int return_big_endian(unsigned char* src, int start, int stop) {
    /* Parses array src from start to stop (non inclusive) and returns the
     * big endian number from that slice numerical byte values
     * (that is, most significant byte first)
     */
    unsigned int result = 0;
    int len = stop - start;
    for (int i = 0; i < len; i++) {
        result += (src[start + i] << (8 * (len - i - 1)));
    }
    return result;
}

Fragment Parser::parse_next() {
    /* Parsing for IP packets. Many fields are ignored.
     * Consult assignment PDF for the fields format
     */

    // Fetch header
    unsigned char header[HEADER_SIZE] = "";
    f.read((char*) header, HEADER_SIZE);

    // Bytes 2 and 3: message length
    unsigned int packet_size = return_big_endian(header, 2, 4);

    // Bytes 4 and 5: identifier
    unsigned int identifier = return_big_endian(header, 4, 6);

    // Third bit from byte 6: MF flag
    char mask = 0x10;
    bool MF = (mask & header[6]) != 0;

    // Last 5 bits from byte 6 + byte 7: offset
    // Mask the last 5 bits from byte 6
    mask = 0x1f;  // 0001 1111
    unsigned int offset = 0;
    offset += (mask & header[6]) << 8;
    offset += header[7];

    // Bytes 12 - 15: source IP, 16-19: dest IP
    unsigned long source = return_big_endian(header, 12, 16);
    unsigned long dest = return_big_endian(header, 16, 20);

    // Read the message in chunks, to be memory efficient
    std::string result("");
    unsigned int message_len = packet_size - HEADER_SIZE;
    char buffer[MSG_CHUNK];
    unsigned int read = 0;
    while (read < message_len) {
        int read_size = MSG_CHUNK;
        if (message_len - read < MSG_CHUNK) {
            read_size = message_len - read;
        }
        f.read(buffer, read_size);
        std::string partial(buffer, (unsigned long) read_size);
        result += partial;
        read += read_size;
    }

    // Create fragment with all the collected data
    return Fragment(message_len, identifier, MF, offset, source, dest, result);
}

int Parser::eof() {
    return f.peek() == EOF;
}


Parser::~Parser() {
}
