#include <iostream>
#include "pwanutils.h"
#include "pwandebug.h"
#include "pwanoptions.h"
#include "pwanstrings.h"

#include "pwancmdlineparser.h"
#include "testtool.h"

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

void testCmdLineParser(int argc, char **argv)
{
    std::vector<pwan::optionsReturn> opRet;
    pwan::t_cmdlineParser cmdP;
    cmdP.setAllowedOption("o", "opensource", "Enables Opensource");
    cmdP.setAllowedOption("a", "autosource", "Enables Autosource");
    cmdP.setAllowedOption("b", "binarysource", "Specifies What kind of binarysource you want(a,b or c)", pwan::RESTRICTED_PARAMETER);
    cmdP.setAllowedOption("c", "canadasource", "Location of canadasource", pwan::ANY_PARAMETER);
    cmdP.setAllowedOption("i", "image", "Image to load", pwan::DEFAULT_PARAMETER);
    cmdP.setValidParameter("binarysource", "a:b:c");
    cmdP.checkCmdLine(argc, argv);
    opRet=cmdP.returnFoundOptions();
    for(std::vector<pwan::optionsReturn>::iterator i = opRet.begin(); i != opRet.end(); ++i)
    {
        std::cout << i->option.c_str() << " ---- " << i->parameter.c_str() << "\n";
    }
}

void testDebugClass(void)
{
    pwan::debug db;
    pwan::debug db2;
    db.dprint("me,","satas?", 14);
    db2.dprint("me2","santa?", 9);
    db2.setDebugLevel(22);
}

void testStringFromInt(void)
{
    std::string hepp = pwan::strings::fromInt(10000);
    if(hepp == "10000")
        pTest.report("pwan::strings::fromInt", pwan::PT_OK);
    else
        pTest.report("pwan::strings::fromInt", pwan::PT_FAIL);
    hepp = pwan::strings::fromInt(10000, 12);
    if(hepp == "000000010000")
        pTest.report("pwan::strings::fromInt", pwan::PT_OK);
    else
        pTest.report("pwan::strings::fromInt", pwan::PT_FAIL);
    hepp = pwan::strings::fromInt(10000, 0, 16);
    if(hepp == "2710")
        pTest.report("pwan::strings::fromInt", pwan::PT_OK);
    else
        pTest.report("pwan::strings::fromInt", pwan::PT_FAIL);
    hepp = pwan::strings::fromInt(4294967297);
    if(hepp == "4294967297")
        pTest.report("pwan::strings::fromInt", pwan::PT_OK);
    else
        pTest.report("pwan::strings::fromInt", pwan::PT_FAIL);
    pTest.writeStatus("pwan::strings::fromInt");
}

void testStringExplode(void)
{
    std::vector<std::string> hepp = pwan::strings::explode("lisa gikk til skolen");
    if(hepp.size() != 4)
        pTest.report("pwan::strings::explode", pwan::PT_WTF);
    else
    {
        if(hepp.at(0) == "lisa" && hepp.at(1) == "gikk" && hepp.at(2) == "til" && hepp.at(3) == "skolen")
            pTest.report("pwan::strings::explode", pwan::PT_OK);
        else
            pTest.report("pwan::strings::explode", pwan::PT_FAIL);
    }
    hepp = pwan::strings::explode("wiii /meeee / slash", "/");
    if(hepp.size() != 3)
        pTest.report("pwan::strings::explode", pwan::PT_WTF);
    else
    {
        if(hepp.at(0) == "wiii " && hepp.at(1) == "meeee " && hepp.at(2) == " slash")
            pTest.report("pwan::strings::explode", pwan::PT_OK);
        else
            pTest.report("pwan::strings::explode", pwan::PT_FAIL);
    }
    pTest.writeStatus("pwan::strings::explode");
}

void testStringToLower(void)
{
    std::string hepp = pwan::strings::toLower("Lisa GIKK tIl SkOlEn!");
    if(hepp == "lisa gikk til skolen!")
        pTest.report("pwan::strings::toLower", pwan::PT_OK);
    else
        pTest.report("pwan::strings::toLower", pwan::PT_FAIL);
    pTest.writeStatus("pwan::strings::toLower");
}

void testStringBase64Encode(void)
{
    std::string hepp = pwan::strings::base64Encode("Lisa Gikk Til Skolen");
    if(hepp == "TGlzYSBHaWtrIFRpbCBTa29sZW4=")
        pTest.report("pwan::strings::base64Encode", pwan::PT_OK);
    else
        pTest.report("pwan::strings::base64Encode", pwan::PT_FAIL);
    hepp = pwan::strings::base64Encode("Undulaten /! I en box!? wtf# \" \\%43");
    if(hepp == "VW5kdWxhdGVuIC8hIEkgZW4gYm94IT8gd3RmIyAiIFwlNDM=")
        pTest.report("pwan::strings::base64Encode", pwan::PT_OK);
    else
        pTest.report("pwan::strings::base64Encode", pwan::PT_FAIL);
    pTest.writeStatus("pwan::strings::base64Encode");
}

void testStringDupeChar(void)
{
    std::vector<char> hepp = pwan::strings::dupechar('3', 4);
    if(hepp.size() != 4)
    {
        pTest.report("pwan::strings::dupechar", pwan::PT_WTF);
        return;
    }
    if(hepp.at(0) == '3' && hepp.at(1) == '3' && hepp.at(2) == '3' && hepp.at(3) == '3')
        pTest.report("pwan::strings::dupechar", pwan::PT_OK);
    else
        pTest.report("pwan::strings::dupechar", pwan::PT_FAIL);
    pTest.writeStatus("pwan::strings::dupechar");
}

int main(int argc, char *argv[])
{
    testStringFromInt();
    testStringExplode();
    testStringToLower();
    testStringBase64Encode();
    testStringDupeChar();
    testCmdLineParser(argc, argv);
    return 0;
}
