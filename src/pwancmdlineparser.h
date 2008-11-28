#ifndef PWANCMDLINEPARSER_H
#define PWANCMDLINEPARSER_H

#include <string>
#include <vector>

namespace pwan
{
    enum e_clpFlag { NO_PARAMETER, ANY_PARAMETER, RESTRICTED_PARAMETER, DEFAULT_PARAMETER };
    enum p_returnValue { P_OK, P_ERROR };
    struct optBlob
    {
        std::string                                 shortOpt;
        std::string                                 longOpt;
        std::string                                 description;
        std::string                                 validParams;
        e_clpFlag                                   flag;
    };

    class t_cmdlineParser
    {
        public:
            t_cmdlineParser(void);
            void setAllowedOption(const std::string &shortOpt, const std::string &longOpt, const std::string &description, e_clpFlag flag = NO_PARAMETER);
            p_returnValue setValidParameter(const std::string &longOpt, const std::string &validParams);
            std::string makeHelp(void);
        private:
            std::vector<optBlob> allowedOptions;
            int defaultOpt;
    };
}

#endif
