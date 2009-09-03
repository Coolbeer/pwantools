#include "teststrings.h"

#include <string>
#include <vector>

#include "pwanstrings.h"
#include "pwantools_enums.h"
#include "testtool.h"

extern pwan::testTool pTest;
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
