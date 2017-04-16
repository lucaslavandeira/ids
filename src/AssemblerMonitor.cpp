#include "AssemblerMonitor.h"
#include "Lock.h"

Packet AssemblerMonitor::add_fragment(Packet& p) {
    Lock lock(m);
    return assembler.add_fragment(p);
}

AssemblerMonitor::AssemblerMonitor(FragmentAssembler &assembler) :
        assembler(assembler)
{
}

