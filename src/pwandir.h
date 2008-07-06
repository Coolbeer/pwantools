#ifndef PWANDIR_H
#define PWANDIR_H

#include <string>
#include <vector>

#include "pwanfileinfo.h"

namespace pwan
{
    class dir
    {
        public:
            dir(const std::string path = ".");
//          fileinfovector readdirectory(std::string path, stringvector filter);
            std::vector<pwan::fileInfo> entryInfoList(stringvector filter);

        private:
            std::string currentpath;
    };

}

#endif
