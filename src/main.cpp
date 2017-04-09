#include <iostream>
#include <fstream>
#include <cstring>
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

    std::vector<Fragment> frags = a.get_fragments();
    frags.
    std::cout << frags.at(0).get_message();
    return 0;
}
