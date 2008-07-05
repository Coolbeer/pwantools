#ifndef PWANFILEIO_H
#define PWANFILEIO_H

#include <string>
#include <fstream>

namespace pwan
{
    class fileio
    {
        public:
            fileio(void);
            fileio(const std::string& filename, std::ios_base::openmode mode = std::ios_base::in);
            ~fileio(void);
            bool open(const std::string& filename, std::ios_base::openmode mode = std::ios_base::in);
            void close(void);

        private:
            std::fstream intFstream;
    };
}

#endif
