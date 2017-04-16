#ifndef IDS_FRAGMENT_H
#define IDS_FRAGMENT_H

#include <string>
#include <vector>

/* Represents an IP packet captured by our detector. Consult assignment handout
 * for the specified format */
class Packet {
    unsigned int message_len;
    unsigned int identifier;
    bool mf;
    unsigned int offset;
    unsigned long source;
    unsigned long dest;
    std::string message;

public:
    Packet(unsigned int message_len,
             unsigned int identifier,
             bool MF,
             unsigned int offset,
             unsigned long source,
             unsigned long dest,
             std::string &message);

    // Create a packet out of smaller fragments
    explicit Packet(std::vector<Packet> &frags);
    ~Packet();

    /* Compares two packets and returns true only if 'this' packet directly
     * precedes (same src, same dest, message offset right before) the other */
    bool precedes(Packet other) const;

    static bool compare(Packet a, Packet b);  // Static compare for std::sort

    bool is_full_packet() const;  // True if MF = 0, offset = 0
    bool is_first() const; // True if offset = 0
    unsigned long get_source() const;
    unsigned long get_dest() const;
    bool get_mf() const;
    std::string get_message() const;
    bool has_addresses(unsigned int src, unsigned int dest) const;

    bool operator==(Packet f) const;
};


#endif //IDS_FRAGMENT_H
