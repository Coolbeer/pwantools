#ifndef PWAN_TESTTOOL_H
#define PWAN_TESTTOOL_H

#include <string>
#include <map>

namespace pwan
{
    enum p_testResult { PT_OK, PT_FAIL, PT_PENDING, PT_WTF };

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
