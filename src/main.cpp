#include "pwanutils.h"

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

void testoptions(void)
{
    pwan::options options;
    for (int i = 99; i != 110; ++i)
    {
        options.set("test" + pwan::strings::fromInt(i, 4), "funker dette?" + pwan::strings::fromInt(i, 8));
    }
    dumplist(options.dump());
}

int main(int argc, char *argv[])
{
    testoptions();
    dumpvector(pwan::strings::explode("lisa gikk til skolen"));
    std::cout << pwan::getextention("firefox.exe") << "\n";
    std::cout << pwan::strings::toLower("HER Var DeT mYe bALL du JA!") << "\n";
    std::cout << pwan::strings::base64Encode("Butikken var aapen i gaar") << "\n";
    dumpvector(pwan::parsebrackets("for loopen går fra[001-10]"));
    return 0;
}
