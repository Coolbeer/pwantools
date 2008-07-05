#include "pwanfileio.h"

pwan::fileio::fileio(void)
{

}

pwan::fileio::fileio(const std::string& filename, std::ios_base::openmode mode)
{
    open(filename, mode);
}

pwan::fileio::~fileio(void)
{

}

bool pwan::fileio::open(const std::string& filename, std::ios_base::openmode mode)
{
    if(filename == "")
        return false;
    intFstream.open(filename.c_str(), mode);
    return intFstream.is_open();
}

void pwan::fileio::close(void)
{
    intFstream.close();
}
