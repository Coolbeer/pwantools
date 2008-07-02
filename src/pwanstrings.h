#ifndef PWANSTRINGS_H
#define PWANSTRINGS_H

#include <string>
#include <vector>
#include <iostream>

namespace pwan
{
    namespace strings
    {
        std::string                     fromInt(long long int number, unsigned int padding = 0, unsigned int base = 10);
        std::vector<std::string>        explode(const std::string& inputstring, std::string explodeby = " ");
        std::string                     toLower(std::string inputstring);
        std::string                     base64Encode(const std::string &text);
        std::vector<char>               dupechar(const char character, unsigned int times);
    }
}

#endif
