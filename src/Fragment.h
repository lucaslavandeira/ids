#ifndef IDS_FRAGMENT_H
#define IDS_FRAGMENT_H

#include <string>
#include <vector>

class Fragment {
    unsigned int message_len;
    unsigned int identifier;
    bool mf;
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

    explicit Fragment(std::vector<Fragment> frags);
    std::string get_message();
    bool precedes(Fragment other);
    ~Fragment();
    bool more_fragments();
    static bool compare(Fragment a, Fragment b);
};



#endif //IDS_FRAGMENT_H
