#ifndef IDS_PRINTER_H
#define IDS_PRINTER_H


#include <iosfwd>
#include <mutex>
#include "Packet.h"

class AlertPrinter {
    std::mutex m;
public:
    AlertPrinter();
    void print(Packet& p, unsigned long rule_index);
};


#endif //IDS_PRINTER_H
