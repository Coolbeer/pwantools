#include <iostream>
#include "pwanutils.h"
#include "pwandebug.h"
#include "pwanoptions.h"
#include "pwanstrings.h"

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
    options.checkCmdLine(argc, argv);
    for (int i = 105; i != 110; ++i)
    {
        options.set("test" + pwan::strings::fromInt(i, 4), "funker dette?" + pwan::strings::fromInt(i, 8));
    }
    dumplist(options.dump());
}

int main(int argc, char *argv[])
{
    testoptions(argc, argv);
    dumpvector(pwan::strings::explode("lisa gikk til skolen"));
    std::cout << pwan::getextention("firefox.exe") << "\n";
    std::cout << pwan::strings::toLower("HER Var DeT mYe bALL du JA!") << "\n";
    std::cout << pwan::strings::base64Encode("Butikken var aapen i gaar") << "\n";
    dumpvector(pwan::parsebrackets("for loopen går fra[001-3]"));
    return 0;
}
