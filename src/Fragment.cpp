#include "Fragment.h"
#include <string>
#include <cstdlib>

Fragment::Fragment(unsigned int message_len, unsigned int identifier, bool MF,
                   unsigned int offset, unsigned long source,
                   unsigned long dest, std::string message) :
        message_len(message_len),
        identifier(identifier),
        MF(MF),
        offset(offset),
        source(source),
        dest(dest),
        message(message)
{
}


std::string Fragment::get_message() {
    return message;
}


Fragment::~Fragment() {
}
