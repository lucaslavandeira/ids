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

Fragment::Fragment(std::vector<Fragment> &frags) {
    if (frags.back().more_fragments()) {
        this->mf = 1;
        return;
    }
    this->identifier = frags.at(0).identifier;
    this->source = frags.at(0).source;
    this->dest = frags.at(0).dest;
    for (iter it = frags.begin(); it != frags.end(); it ++) {
        this->message_len += it->message_len;
        this->message += it->message;
    }
    this->mf = 0;
    this->offset = 0;
}
std::string Fragment::get_message() const {
    return message;
}


Fragment::~Fragment() {
}


bool Fragment::compare(Fragment a, Fragment b) {
    /* Sorts fragments by (source, dest, ID) tuple, then by their offset
     * (lower first)
     */
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

bool Fragment::has_addresses(unsigned int src, unsigned int dest)const {
    return (this->source == src || !src) && (this->dest == dest || !dest);
}

unsigned long Fragment::get_source() const {
    return source;
}

unsigned long Fragment::get_dest() const {
    return dest;
}

bool Fragment::is_full_packet() {
    return !offset && !mf;
}

bool Fragment::is_first() {
    return offset == 0;
}

bool Fragment::operator==(Fragment f) {
    return this->message == f.message &&
           this->source == f.source &&
           this->dest == f.dest &&
           this->identifier == f.identifier;
}


