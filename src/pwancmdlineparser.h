#ifndef PWANCMDLINEPARSER_H
#define PWANCMDLINEPARSER_H

#include <string>

namespace pwan
{
    enum e_clpFlag { NO_PARAMETER = 0, ANY_PARAMETER = 1, DEFAULT_PARAMETER = 2 };
    class t_cmdlineParser
    {
        void setAllowedOption(const std::string &shortOpt, const std::string &longOpt, const std::string &description, e_clpFlag flag = NO_PARAMETER);
    };
}

#endif
