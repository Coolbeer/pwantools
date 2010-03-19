#ifndef PWANDEBUG_H
#define PWANDEBUG_H

#include <string>
#include <vector>

/*
    Debuglevels:
        1  -  Normal output for user
        2  -  Normal verbose
        3  -  Very verbose(currently used for debugging)
        4  -  The extreme verbose debugging(lots of spam)
*/

namespace pwan
{
    struct t_savedMessage
    {
            std::string                             Message;
            unsigned int                            debugLevel;
    };

    class debug
    {
        public:
                                                    debug(void);
            void                                    dprint(const std::string &from, const std::string &message, const unsigned int &p_debugLevel = 1);
            void                                    dprint(const std::string &message, const unsigned int p_debugLevel = 1);
            int                                     setDebugLevel(const unsigned int &debugLevel);
            int                                     getDebugLevel(void);
            void                                    mute(void);
            void                                    unMute(void);
        private:
            std::string                             className;
            static std::vector<t_savedMessage>      savedMessages;
            static unsigned int                     debugLevel;
            unsigned int                            maxSavedLog;
            bool                                    iMute;
    };
}
#endif
