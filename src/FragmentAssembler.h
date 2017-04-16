#ifndef IDS_FRAGMENTASEMBLER_H
#define IDS_FRAGMENTASEMBLER_H

#include <vector>
#include "Packet.h"

class FragmentAssembler {
    std::vector<Packet> frags;
    std::vector<Packet> packets;

public:
    FragmentAssembler();
    // Pushes a packet (complete or not) to the assembler, and runs assemble()
    Packet add_fragment(Packet& p);

    const std::vector<Packet>* get_packets() const;
private:
    /* Attempts to assemble a full packet from the fragments in 'frags'.
     * On success the result is pushes to 'packets'. Only at most one packet is
     * pushed per function call */
    void assemble();

    FragmentAssembler(FragmentAssembler&) = delete;
    void operator=(FragmentAssembler&) = delete;
};

#endif //IDS_FRAGMENTASEMBLER_H


