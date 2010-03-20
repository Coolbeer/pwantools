#include <iostream>
#include "pwanutils.h"
#include "pwandebug.h"
#include "pwanoptions.h"
#include "pwanstrings.h"
#include "pwandebug.h"

#include "pwancmdlineparser.h"
#include "testtool.h"
#include "teststrings.h"
#include "testutils.h"
#include "testcmdlineparser.h"
#include "testdebug.h"

pwan::testTool pTest;

void dumplist(std::list<std::string> dumpvalue)
{
    std::list<std::string>::iterator iter;
    for (iter = dumpvalue.begin(); iter != dumpvalue.end(); ++iter)
    {
        std::cout << "\"" << (*iter) << "\"\n";
    }
}

void dumpvector(std::vector<std::string> dumpvalue)
{
    std::vector<std::string>::iterator iter;
    for (iter = dumpvalue.begin(); iter != dumpvalue.end(); ++iter)
    {
        std::cout << "\"" << (*iter) << "\"\n";
    }
}

void testCmdLineParser(void)
{
    testCheckCmdLine();
}

void testStrings(void)
{
    testStringFromInt();
    testStringExplode();
    testStringToLower();
    testStringBase64Encode();
    testStringDupeChar();
}
void testUtils(void)
{
    testGetExtention();
}

void testDebug(void)
{
    getDebugLevel();
    setDebugLevel();
}

int main(void)
{
    testStrings();
    testUtils();
    testCmdLineParser();
    testDebug();
    return 0;
}
