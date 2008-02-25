#ifndef PWANPCK_H
#define PWANPCK_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace pwan
{
    class pck
    {
        public:
            pck                                     (std::string fileName = "");
            int                                     load(std::string fileName = "");

        private:
            std::ifstream                           pckInputFile;
            std::vector< std::vector<char> >        tempImages;
            void                                    decompressRle(void);
    };
}

#endif
