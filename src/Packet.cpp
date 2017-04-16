#include <cstdlib>
#include "Packet.h"

using iter = std::vector<Packet>::iterator;

Packet::Packet(unsigned int message_len, unsigned int identifier, bool MF,
                   unsigned int offset, unsigned long source,
                   unsigned long dest, std::string& message) :
        message_len(message_len),
        identifier(identifier),
        mf(MF),
        offset(offset),
        source(source),
        dest(dest),
        message(std::string(message))
{
}

Packet::Packet(std::vector<Packet> &frags) {
    if (frags.back().get_mf()) {
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

Packet::~Packet() {
}


bool Packet::compare(Packet a, Packet b) {
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

bool Packet::get_mf() const {
    return mf;
}

bool Packet::precedes(Packet other) const {
    return this->identifier == other.identifier &&
           this->source == other.source &&
           this->dest == other.dest &&
           this->offset + this->message_len == other.offset;
}

bool Packet::has_addresses(unsigned int src, unsigned int dest)const {
    return (this->source == src || !src) && (this->dest == dest || !dest);
}

unsigned long Packet::get_source() const {
    return source;
}

unsigned long Packet::get_dest() const {
    return dest;
}

bool Packet::is_full_packet() const {
    return !offset && !mf;
}

bool Packet::is_first() const {
    return offset == 0;
}

std::string Packet::get_message() const {
    return message;
}


bool Packet::operator==(Packet f) const {
    return this->message == f.message &&
           this->source == f.source &&
           this->dest == f.dest &&
           this->identifier == f.identifier;
}

Packet::Packet(Packet &&other) {
    this->message_len = other.message_len;
    this->source = other.source;
    this->dest = other.dest;
    this->identifier = other.identifier;
    this->offset = other.offset;
    this->mf = other.mf;
    this->message = other.message;
}

