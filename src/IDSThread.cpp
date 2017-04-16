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
        r_monitor.check_and_print(result);
    }
}

IDSThread::~IDSThread() {
}
