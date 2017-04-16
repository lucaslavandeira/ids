#ifndef IDS_ASSEMBLERMONITOR_H
#define IDS_ASSEMBLERMONITOR_H


#include <mutex>
#include <vector>
#include "FragmentAssembler.h"

// Monitor for the FragmentAssembler class, to protect its thread unsafe vector
// manipulation
class AssemblerMonitor {
    std::mutex m;
    FragmentAssembler& assembler;

public:
    explicit AssemblerMonitor(FragmentAssembler& assembler);
    Packet add_fragment(Packet& p);
};


#endif //IDS_ASSEMBLERMONITOR_H
