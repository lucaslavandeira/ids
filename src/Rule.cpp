#include "Rule.h"

Rule::Rule(unsigned long src, unsigned long dest, unsigned long threshold,
           std::vector<std::string> words)  :
        src(src),
        dest(dest),
        threshold(threshold),
        words(words)
{
}
