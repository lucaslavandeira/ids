#include <iostream>
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


    for (int i = 2; i < argc; i++) {
        Parser a(argv[i], "r");
    }
    return 0;
}
