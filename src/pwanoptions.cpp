#include "pwanoptions.h"
#include "pwandebug.h"

extern pwan::debug debug;

pwan::options::options(void)
{
    className = "pwan::options";
}

int pwan::options::set(const std::string& name, const std::string& value)
{
    std::string functionName = "set";
    ::debug.print(className + "::" + functionName, name + " = " + value, 3);
    internalData[name] = value;
    return 0;
}

std::string pwan::options::get(const std::string& name)
{
    std::string functionName = "get";
    ::debug.print(className + "::" + functionName, "name = " + name, 3);
    if(internalData.find(name) != internalData.end())
    {
        ::debug.print(className + "::" + functionName, "Returning: " + (*(internalData.find(name))).second, 3);
        return (*(internalData.find(name))).second;
    }
    else
    {
        ::debug.print(className + "::" + functionName, "Returning empty string(option not found) " , 3);
        return "";
    }
}

std::list<std::string> pwan::options::dump(void)
{
    std::string functionName = "dump";
    ::debug.print(className + "::" + functionName, "Dumping options", 3);
    std::list<std::string> returnvalue;
    for(std::map<std::string, std::string>::iterator iter = internalData.begin(); iter != internalData.end(); ++iter)
    {
        returnvalue.push_back((*iter).first);
        returnvalue.push_back((*iter).second);
    }
    return returnvalue;
}
