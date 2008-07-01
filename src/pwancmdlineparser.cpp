#include "pwancmdlineparser.h"
#include "pwandebug.h"

extern pwan::debug debug;

pwan::cmdLineParser::cmdLineParser(void)
{
    className = "cmdLineParser";
}

pwan::cmdLineParser::cmdLineParser(int argc, char *argv[])
{
    className = "cmdLineParser";
}

bool pwan::cmdLineParser::parse(int argc, char *argv[])
{
    return false;
}
