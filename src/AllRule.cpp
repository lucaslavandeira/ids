#include "AllRule.h"


AllRule::AllRule(unsigned long src, unsigned long dest, unsigned long threshold,
                       std::vector<std::string> words) :
        Rule(src, dest, threshold, words)
{
}
