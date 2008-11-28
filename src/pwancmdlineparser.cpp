#include "pwancmdlineparser.h"

void pwan::t_cmdlineParser::setAllowedOption(const std::string &shortOpt, const std::string &longOpt, const std::string &description, e_clpFlag flag)
{
    optionBlob newOption;
    newOption.shortOpt = shortOpt;
    newOption.longOpt = longOpt;
    newOption.description = description;
    newOption.flag = flag;
    allowedOptions.push_back(newOption);
}
int pwan::t_cmdlineParser::setValidParameter(const std::string &longOpt, const std::string &validParams)
{
    std::vector<optionBlob>::iterator iter;
    for(iter = allowedOptions.begin(); iter != allowedOptions.end(); ++iter)
    {
        if(longOpt == iter->longOpt)
        {
            iter->validParams = validParams;
            return 0;
        }
    }
    return -1;
}
