#include <iostream>

#include "pwandebug.h"
#include "pwanstrings.h"
#include "pwantools_enums.h"

unsigned int pwan::debug::debugLevel;
std::vector<pwan::t_savedMessage> pwan::debug::savedMessages;

void pwan::debug::mute()
{
    iMute = true;
}

void pwan::debug::unMute()
{
    iMute = false;
}

void pwan::debug::dprint(const std::string &from, const std::string &message, const unsigned int &p_debugLevel)
{
    std::string completeMessage;
    if(from != "")
        completeMessage = from + ": ";
    completeMessage = completeMessage + message;

    if(debugLevel >= p_debugLevel)
    {
        if(!iMute)
        {
            std::cout << completeMessage;
            std::cout.flush();
        }
    }
    else
    {
        t_savedMessage newMessage;
        newMessage.Message = completeMessage;
        newMessage.debugLevel = p_debugLevel;
        savedMessages.push_back(newMessage);
        if(savedMessages.size() > maxSavedLog)
            savedMessages.erase(savedMessages.begin());
    }
}

void pwan::debug::dprint(const std::string &message, const unsigned int p_debugLevel)
{
    dprint("", message + "\n", p_debugLevel);
}

int pwan::debug::setDebugLevel(const unsigned int NewdebugLevel)
{
    std::string functionName("setDebugLevel");
    static std::vector<t_savedMessage>::iterator iter;
    if(NewdebugLevel > 0 && NewdebugLevel < 20)
        debugLevel = NewdebugLevel;

    dprint(className + "::" + functionName, "Setting debug level " + pwan::strings::fromInt(debugLevel) + "\n", 3);
    dprint(className + "::" + functionName, "Printing out saved messages(if any) from lower debuglevels\n", 3);
    iter = savedMessages.begin();
    while(savedMessages.size() != 0)
    {
        if((*iter).debugLevel <= debugLevel)
        {
            dprint((*iter).Message);
            savedMessages.erase(iter);
        }
        else
            ++iter;
    }
    if(NewdebugLevel == debugLevel)
        return P_OK;
    else
        return P_ERROR;
}

int pwan::debug::getDebugLevel(void)
{
    return debugLevel;
}
