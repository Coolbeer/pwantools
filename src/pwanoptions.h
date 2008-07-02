#ifndef PWANOPTIONS_H
#define PWANOPTIONS_H

#include <string>
#include <list>
#include <map>
#include <vector>

namespace pwan
{
    struct optionBlob
    {
        char                                        shortOpt;
        std::string                                 longOpt;
        std::string                                 description;
    };

    class options
    {
        public:
                                                    options(void);
            int                                     set(const std::string& name, const std::string& value);
            std::string                             get(const std::string& name);
            std::list<std::string>                  dump(void);

            void                                    setFlag(const char shortOpt, const std::string& longOpt, const std::string& description);
        private:
            std::map<std::string, std::string>      internalData;
            std::string className;
            std::vector<optionBlob>                 allowedOptions;
    };
}

#endif
