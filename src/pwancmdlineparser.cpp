#include "pwancmdlineparser.h"

void pwan::t_cmdlineParser::setAllowedOption(const std::string &shortOpt, const std::string &longOpt, const std::string &description, e_clpFlag flag)
{
    if(shortOpt == "" || longOpt == "" || description == "" || flag == NO_PARAMETER)
        return;
    return;
}
