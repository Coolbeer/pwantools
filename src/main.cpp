#include <iostream>
#include "pwanutils.h"
#include "pwandebug.h"
#include "pwanoptions.h"
#include "pwanstrings.h"

#include "pwancmdlineparser.h"
#include "testtool.h"
#include "teststrings.h"
#include "testutils.h"
#include "testcmdlineparser.h"

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

void testoptions(int argc, char **argv)
{
    pwan::options options;
    pwan::debug debug;
    options.setOption("V", "version", "Prints versionstring", "!");
    options.setOption("b", "browserid", "Set browserid", "");
    options.setOption("", "secure-protocol", "choose secure protocol, one of auto, SSLv2, SSLv3, and TLSv1", "auto:SSLv2:SSLv3:TLSv1");
    options.setOption("", "url", "", "*");
    options.setOption("d", "debug", "Enable verbose debug info", "!");
    options.checkIniFile("setup.ini");
    options.checkCmdLine(argc, argv);
    std::cout << options.makeHelp();
    if(options.get("debug") == "true")
        debug.setDebugLevel(3);
    for (int i = 105; i != 110; ++i)
    {
        options.set("test" + pwan::strings::fromInt(i, 4), "funker dette?" + pwan::strings::fromInt(i, 8));
    }
    dumplist(options.dump());
}

void testDebugClass(void)
{
    pwan::debug db;
    pwan::debug db2;
    db.dprint("me,","satas?", 14);
    db2.dprint("me2","santa?", 9);
    db2.setDebugLevel(22);
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

int main(void)
{
    testStrings();
    testUtils();
    testCmdLineParser();
    return 0;
}
