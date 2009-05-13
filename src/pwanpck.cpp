#include "pwanpck.h"

pwan::pck::pck(std::string fileName)
{
    if(fileName != "")
        load(fileName);
}

int pwan::pck::load(std::string fileName)
{
    std::vector<char> lastBytes;
    std::vector<char> emptyCharVector;
    char tempChar;
    tempImages.push_back( emptyCharVector );

    if(pckInputFile.is_open())
        pckInputFile.close();
    pckInputFile.open(fileName.c_str(), std::ios::in | std::ios::binary);
    if(!pckInputFile.is_open())
    {
        std::cout << "Can't open file?\n";
        return 1;
    }
    while(pckInputFile.good())                                                                                                     //Read file one byte at a time
    {
        pckInputFile.read(&tempChar, 1);
        //if(pckInputFile.gcount() != 1)
        //    break;
        if(lastBytes.size() == 3)
            lastBytes.erase(lastBytes.begin());
        lastBytes.push_back(tempChar);
        tempImages.at(tempImages.size() -1).push_back(tempChar);
        if((unsigned char)lastBytes.at(0) == 254 && (unsigned char)lastBytes.at(1) == 255 && (unsigned char)lastBytes.at(2) == 255)            //Found end of image
        {
            tempImages.at(tempImages.size() -1).erase(tempImages.at(tempImages.size() -1).end() - 3, tempImages.at(tempImages.size() -1).end());
            tempImages.push_back(emptyCharVector);
        }
    }
    pckInputFile.close();
/*    std::ofstream outputfile;
    std::string outputFilename;
    for(unsigned int i = 0; i != tempImages.size()-1; ++i)
    {
        outputFilename = "test" + pwan::inttostring(i,2) + ".raw";
        outputfile.open(outputFilename.c_str(), std::ios::out | std::ios::binary);
        outputfile.write(std::string(tempImages.at(i).begin(), tempImages.at(i).end()).c_str(), tempImages.at(i).size());
        outputfile.close();
    }
*/
    decompressRle();

    return 0;
}

void pwan::pck::decompressRle(void)
{
/*    std::cout << "hmm?\n";
    for(std::vector< std::vector<char> >::iterator iter = tempImages.begin(); iter != tempImages.end(); ++iter)
    {
        std::cout << "image: " << iter - tempImages.begin() << "\n";
        unsigned char blankLines = (*iter).at(0);
        (*iter).erase((*iter).begin());
        if(blankLines != 0)
        {
            (*iter).insert((*iter).begin(), (blankLines * 32), 254);
        }
        for(std::vector<char>::iterator iter2 = (*iter).begin() + (blankLines *32); iter2 != (*iter).end(); ++iter2)
        {
            if((unsigned char)(*iter2) == 254 && iter2 +1 != (*iter).end())
            {
                iter2 = (*iter).erase(iter2);
                unsigned char blankPixels = (*iter2);
                iter2 = (*iter).erase(iter2);
                std::cout << (int)blankPixels << "\n";
                (*iter).insert(iter2, blankPixels, 254);
                iter2 = iter2 + (unsigned char)blankPixels +1;
            }
        }
    }
*/
}
