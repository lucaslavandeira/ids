#ifndef IDS_IDS_H
#define IDS_IDS_H


#include "Thread.h"
#include "AssemblerMonitor.h"
#include "RulesMonitor.h"
#include "Parser.h"
#include "AlertPrinter.h"

class IDSThread : public Thread {
    Parser parser;

    AssemblerMonitor &monitor;
    RulesMonitor &r_monitor;

public:
    IDSThread(const char* path, AssemblerMonitor& monitor,
              RulesMonitor& r_monitor);
    void run();
    ~IDSThread();
};


#endif //IDS_IDS_H
