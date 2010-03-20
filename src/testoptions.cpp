#include "testoptions.h"
#include "testtool.h"
#include "pwanoptions.h"

extern pwan::testTool pTest;

void testSetValue(void)
{
    pwan::options tstOpt;
    tstOpt.mute();
    tstOpt.setValue("test1", "value1");

    if(tstOpt.getValue("test1") == "value1")
        pTest.report("pwan::options::setValue", pwan::PT_OK);
    else
        pTest.report("pwan::options::setValue", pwan::PT_FAIL);
    pTest.writeStatus("pwan::options::setValue");
}
