#include "pwancmdlineparser.h"
#include "../config.h"

pwan::t_cmdlineParser::t_cmdlineParser(void)
{
    defaultOpt = 0;
}

void pwan::t_cmdlineParser::setAllowedOption(const std::string &shortOpt, const std::string &longOpt, const std::string &description, e_clpFlag flag)
{
    optBlob newOption;
    newOption.shortOpt = shortOpt;
    newOption.longOpt = longOpt;
    newOption.description = description;
    newOption.flag = flag;
    allowedOptions.push_back(newOption);
    if(flag == DEFAULT_PARAMETER)
        defaultOpt = allowedOptions.size()-1;
}

pwan::p_returnValue pwan::t_cmdlineParser::setValidParameter(const std::string &longOpt, const std::string &validParams)
{
    std::vector<optBlob>::iterator iter;
    for(iter = allowedOptions.begin(); iter != allowedOptions.end(); ++iter)
    {
        if(longOpt == iter->longOpt)
        {
            iter->validParams = validParams;
            return P_OK;
        }
    }
    return P_ERROR;
}

std::string pwan::t_cmdlineParser::makeHelp(void)
{
    std::string returnValue;
    std::vector<optBlob>::iterator opBlobIter;
    bool hasOpt = false;
    unsigned int longestShort = 0;
    unsigned int longestLong = 0;

    returnValue = "Usage: ";
    returnValue += PACKAGE_NAME;

    if((defaultOpt != 0 && allowedOptions.size() > 1) || (defaultOpt == 0 && allowedOptions.size() > 0))
    {
        returnValue += " [OPTIONS]";
        hasOpt = true;
    }
    if(defaultOpt != 0)
    {
        returnValue += " [" + allowedOptions.at(defaultOpt).longOpt + "]";
    }
    if(hasOpt)
    {
        returnValue += "\n\nWhere [OPTIONS] is one of the following:\n";
        for(opBlobIter = allowedOptions.begin(); opBlobIter != allowedOptions.end(); ++opBlobIter)
        {
            if(opBlobIter->shortOpt.size() > longestShort)
                longestShort = opBlobIter->shortOpt.size();
            if(opBlobIter->longOpt.size() > longestLong)
                longestLong = opBlobIter->longOpt.size();
        }
        for(opBlobIter = allowedOptions.begin(); opBlobIter != allowedOptions.end(); ++opBlobIter)
        {
            if(opBlobIter->longOpt == allowedOptions.at(defaultOpt).longOpt)
                continue;
            if(opBlobIter->shortOpt != "")
                returnValue += "  -" + opBlobIter->shortOpt + "," + std::string(longestShort - opBlobIter->shortOpt.size() + 2, ' ');
            else
                returnValue += std::string(longestShort + 6, ' ');
                returnValue += "--" + opBlobIter->longOpt + std::string(longestLong - opBlobIter->longOpt.size() + 5, ' ');
                returnValue += opBlobIter->description + "\n";
        }
    }
    returnValue += "\n";
    return returnValue;
}
