#include "Fragment.h"
#include <cstdlib>

using iter = std::vector<Fragment>::iterator;

Fragment::Fragment(unsigned int message_len, unsigned int identifier, bool MF,
                   unsigned int offset, unsigned long source,
                   unsigned long dest, std::string message) :
        message_len(message_len),
        identifier(identifier),
        mf(MF),
        offset(offset),
        source(source),
        dest(dest),
        message(message)
{
}

Fragment::Fragment(std::vector<Fragment> frags) {
    this->identifier = frags.at(0).identifier;
    this->source = frags.at(0).source;
    this->dest = frags.at(0).dest;
    this->mf = 0;
    this->offset = 0;
    for (iter it = frags.begin(); it != frags.end(); it ++) {
        this->message_len += it->message_len;
        this->message += it->message;
    }
}
std::string Fragment::get_message() {
    return message;
}


Fragment::~Fragment() {
}


bool Fragment::compare(Fragment a, Fragment b) {
    if (a.source != b.source) {
        return a.source < b.source;
    }

    if (a.dest != b.dest) {
        return a.dest < b.dest;
    }

    if (a.identifier != b.identifier) {
        return a.identifier < b.identifier;
    }

    return a.offset < b.offset;
}

bool Fragment::more_fragments() {
    return mf;
}

bool Fragment::precedes(Fragment other) {
    return this->identifier == other.identifier &&
           this->source == other.source &&
           this->dest == other.dest &&
           this->offset + this->message_len == other.offset;
}
