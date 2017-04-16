#include <iostream>
#include "IDSThread.h"

IDSThread::IDSThread(const char *path, AssemblerMonitor &monitor,
                     RulesMonitor &r_monitor) :
        parser(Parser(path)),
        monitor(monitor),
        r_monitor(r_monitor)
{
}

void IDSThread::run() {
    while (!parser.eof()) {
        Packet f(parser.parse_next());
        Packet result = monitor.add_fragment(f);
        if (result.get_mf()) { // No new packets were assembled
            continue;
        }

        for (long unsigned i = 0; i < r_monitor.rules_size(); i++) {
            if (r_monitor.check(result)) {
                r_monitor.print(result, i);
            }
        }
    }
}

IDSThread::~IDSThread() {
}
