#include "AssemblerMonitor.h"
#include "Lock.h"

Packet AssemblerMonitor::add_fragment(Packet& p) {
    Lock lock(m);
    return assembler.add_fragment(p);
}

const std::vector<Packet> *AssemblerMonitor::get_packets() {
    return assembler.get_packets();
}

AssemblerMonitor::AssemblerMonitor(FragmentAssembler &assembler) :
        assembler(assembler)
{
}

