#include <iostream>
#include "IDSThread.h"

IDSThread::IDSThread(const char *path, AssemblerMonitor &monitor,
                     RulesMonitor &r_monitor) :
        parser(Parser(path)),
        monitor(monitor),
        r_monitor(r_monitor)
{
}


void print_alert(Packet p, unsigned long rule_index) {
    std::cout << "Rule " << rule_index <<": ALERT! " <<
              std::hex << p.get_source() << " -> " <<
              std::hex << p.get_dest() << ":";

    std::string message = p.get_message();
    for (unsigned long j = 0; j < (message.size()); j++) {
        std::cout <<  " " << std::hex << +message.at(j);
    }
    std::cout << std::endl;
}

void IDSThread::run() {
    while (!parser.eof()) {
        Packet f(parser.parse_next());
        monitor.add_fragment(f);
    }

    const std::vector<Packet> packets = *monitor.get_packets();

    for (Packet p : packets) {
        for (long unsigned i = 0; i < r_monitor.rules_size(); i++) {
            if (r_monitor.check(p)) {
                print_alert(p, i);
            }
        }
    }
}

IDSThread::~IDSThread() {
}
