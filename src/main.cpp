#include <iostream>
#include <fstream>
#include <cstring>
#include <errno.h>
#include "Packet.h"
#include "Parser.h"

using std::cerr;
using std::endl;
int main(int argc, char** argv) {
    if (argc < 3) {
        cerr << "ERROR: Invalid arguments\n"
                       "Usage: ./tp <cfg file> <src files> ..." << endl;
        return 1;
    }

    /* Rules parsing here */

    Parser a(argv[2]);

    return 0;
}
