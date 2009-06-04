#include <iostream>
#include "pwanutils.h"
#include "pwandebug.h"
#include "pwanoptions.h"
#include "pwanstrings.h"

#include "pwancmdlineparser.h"
pwan::debug debug;

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

int main(int argc, char *argv[])
{
    testoptions(argc, argv);
    dumpvector(pwan::strings::explode("lisa gikk til skolen"));
    std::cout << pwan::getextention("firefox.exe") << "\n";
    std::cout << pwan::strings::toLower("HER Var DeT mYe bALL du JA!") << "\n";
    std::cout << pwan::strings::base64Encode("Butikken var aapen i gaar") << "\n";
    dumpvector(pwan::parsebrackets("for loopen g�r fra[001-3]"));
    testCmdLineParser(argc, argv);
    return 0;

}
