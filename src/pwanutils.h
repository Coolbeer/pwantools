#ifndef PWANUTILS_H
#define PWANUTILS_H

#include <vector>
#include <string>
#include <list>
#include <map>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

#include "pwanoptions.h"
#include "pwanpck.h"

typedef std::vector<std::string> stringvector;

namespace pwan
{
    class doubleint
    {
        public:
            int x;
            int y;
    };

    namespace html
    {
        stringvector    getImageLinks(std::string filename);
        stringvector    getLinks(std::string filename);
    }

    namespace ascii
    {
        std::vector<char>                           dupechar(const char character, unsigned int times);
    }

    enum fileWriteMode {OverWrite, Append};

    std::string         inttostring(long long int number, int padding = 0, int base = 10);
    stringvector        explodestring(std::string inputstring, std::string explodeby = " ");
    std::string         getextention(std::string filename);
    std::string         stringtolower(std::string inputstring);
    float               calculatezoom(int imagedims[2], int displaydims[2]);
    doubleint           calculateoffset(int imagedims[2], int displaydims[2]);

    std::string         readFile(const std::string filename);
    std::string         base64Encode(const std::string text);
    stringvector        parsebrackets(const std::string url);
    int                 writefile(const std::string filename, const char data[], const int datasize, const int writemode);
}

#endif
