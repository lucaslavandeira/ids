#ifndef IDS_ASSEMBLERMONITOR_H
#define IDS_ASSEMBLERMONITOR_H


#include <mutex>
#include <vector>
#include "FragmentAssembler.h"

class AssemblerMonitor {
    std::mutex m;
    FragmentAssembler& assembler;

public:
    explicit AssemblerMonitor(FragmentAssembler& assembler);
    void add_fragment(Packet& p);
    const std::vector<Packet>* get_packets();
};


#endif //IDS_ASSEMBLERMONITOR_H
