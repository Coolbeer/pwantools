#include "testcmdlineparser.h"

#include "pwancmdlineparser.h"
#include "testtool.h"

extern pwan::testTool pTest;

void testCheckCmdLine(void)
{
    pwan::t_cmdlineParser cmdLineParser;
    int argc = 2;
    char *argv[2] = {const_cast<char*>("hepp"),const_cast<char*>("-s")};
    cmdLineParser.setAllowedOption("s", "suppe", "suppekjøkken");
    if(cmdLineParser.checkCmdLine(argc, argv) != pwan::P_OK)
    {
        pTest.report("pwan::t_cmdlineParser::checkCmdLine", pwan::PT_FAIL);
        return;
    }
    std::vector<pwan::optionsReturn> opRet = cmdLineParser.returnFoundOptions();
    if(opRet.empty())
        pTest.report("pwan::t_cmdlineParser::checkCmdLine", pwan::PT_FAIL);
    else if(opRet.at(0).option == "suppe" && opRet.at(0).parameter.empty())
        pTest.report("pwan::t_cmdlineParser::checkCmdLine", pwan::PT_OK);
    pTest.writeStatus("pwan::t_cmdlineParser::checkCmdLine");
}
