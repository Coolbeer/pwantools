#include "testutils.h"

#include "pwantools_enums.h"
#include "testtool.h"
#include "pwanutils.h"

#include <fstream>

extern pwan::testTool pTest;

void testGetExtention(void)
{
    std::string hepp;
    std::ofstream testfile("img.tmp");
    pwan::p_returnValue ret = pwan::getextention("img.tmp", hepp);
    if(ret != pwan::P_OK)
        pTest.report("pwan::getextention", pwan::PT_PENDING);
    else
    {
        if(hepp == ".tmp")
            pTest.report("pwan::getextention", pwan::PT_OK);
        else
            pTest.report("pwan::getextention", pwan::PT_FAIL);
    }
    hepp = pwan::getextention("img.tmp");
    if(hepp == ".tmp")
        pTest.report("pwan::getextention", pwan::PT_OK);
    else
        pTest.report("pwan::getextention", pwan::PT_PENDING);
    pTest.writeStatus("pwan::getextention");
}