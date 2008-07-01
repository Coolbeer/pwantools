#ifndef PWANCMDLINEPARSER_H
#define PWANCMDLINEPARSER_H

#include <string>

namespace pwan
{
    class cmdLineParser
    {
        public:
            cmdLineParser(void);
            cmdLineParser(int argc, char *argv[]);
            bool parse(int argc, char *argv[]);
        private:
            std::string className;
    };
}

#endif
