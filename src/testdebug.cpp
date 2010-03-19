#include "testdebug.h"

#include "pwandebug.h"
#include "pwantools_enums.h"
#include "testtool.h"

extern pwan::testTool pTest;

void getDebugLevel(void)
{
    pwan::debug newDebug;
    newDebug.mute();
    if(newDebug.getDebugLevel() == 1)
        pTest.report("pwan::debug::getDebugLevel", pwan::PT_OK);
    else
        pTest.report("pwan::debug::getDebugLevel", pwan::PT_FAIL);
    pTest.writeStatus("pwan::debug::getDebugLevel");
}

void setDebugLevel(void)
{
    pwan::debug newDebug;
    newDebug.mute();
    newDebug.setDebugLevel(5);
    if(newDebug.getDebugLevel() == 5)
        pTest.report("pwan::debug::setDebugLevel", pwan::PT_OK);
    else
        pTest.report("pwan::debug::setDebugLevel", pwan::PT_FAIL);

    newDebug.setDebugLevel(-5);
    if(newDebug.getDebugLevel() == -5)
        pTest.report("pwan::debug::setDebugLevel", pwan::PT_FAIL);
    else
        pTest.report("pwan::debug::setDebugLevel", pwan::PT_OK);

    newDebug.setDebugLevel(15);
    newDebug.setDebugLevel(-5);
    if(newDebug.getDebugLevel() == 15)
        pTest.report("pwan::debug::setDebugLevel", pwan::PT_OK);
    else
        pTest.report("pwan::debug::setDebugLevel", pwan::PT_FAIL);

    if(newDebug.setDebugLevel(-5) == pwan::P_OK)
        pTest.report("pwan::debug::setDebugLevel", pwan::PT_FAIL);
    else if(newDebug.setDebugLevel(-5) == pwan::P_ERROR)
        pTest.report("pwan::debug::setDebugLevel", pwan::PT_OK);
    pTest.writeStatus("pwan::debug::setDebugLevel");
}
