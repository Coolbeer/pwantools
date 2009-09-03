#ifndef PWAN_TESTTOOL_H
#define PWAN_TESTTOOL_H

#include <string>
#include <map>

#include "pwantools_enums.h"

namespace pwan
{
    struct storage
    {
        int                                     noOfTests;
        int                                     okTests;
        int                                     failedTests;
        int                                     pendingTests;
        int                                     wtfTests;
    };

    class testTool
    {
        public:
            void                                report(std::string who, p_testResult result);
            void                                writeStatus(std::string who);
        private:
            std::map<std::string, storage>      internalStorage;
    };
}

#endif
