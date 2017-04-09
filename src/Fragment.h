#ifndef IDS_FRAGMENT_H
#define IDS_FRAGMENT_H

#include <string>

class Fragment {
    unsigned int message_len;
    unsigned int identifier;
    bool MF;
    unsigned int offset;
    unsigned long source;
    unsigned long dest;
    std::string message;

public:
    Fragment(unsigned int message_len,
             unsigned int identifier,
             bool MF,
             unsigned int offset,
             unsigned long source,
             unsigned long dest,
             std::string message);

    std::string get_message();

    ~Fragment();
};



#endif //IDS_FRAGMENT_H
