#include "testtool.h"

#include <iostream>

void pwan::testTool::report(std::string who, p_testResult result)
{
    storage tmpStorage;
    std::map<std::string, storage>::iterator iter;
    tmpStorage.noOfTests = 1;
    tmpStorage.okTests = 0;
    tmpStorage.failedTests = 0;
    tmpStorage.pendingTests = 0;
    tmpStorage.wtfTests = 0;
    if(result == PT_OK)
        tmpStorage.okTests = 1;
    else if(result == PT_FAIL)
        tmpStorage.failedTests = 1;
    else if(result == PT_PENDING)
        tmpStorage.pendingTests = 1;
    else if(result == PT_WTF)
        tmpStorage.wtfTests = 1;
    iter = internalStorage.find(who);
    if(iter == internalStorage.end())
    {
        internalStorage[who] = tmpStorage;
        return;
    }
    internalStorage[who].noOfTests += tmpStorage.noOfTests;
    internalStorage[who].okTests += tmpStorage.okTests;
    internalStorage[who].failedTests += tmpStorage.failedTests;
    internalStorage[who].pendingTests += tmpStorage.pendingTests;
    internalStorage[who].wtfTests += tmpStorage.wtfTests;
}

void pwan::testTool::writeStatus(std::string who)
{
    if(internalStorage.find(who) == internalStorage.end())
    {
        std::cout << "No test found for " << who << "!\n";
        return;
    }
    std::cout << who << ": TOTAL[" << internalStorage[who].noOfTests << "], ";
    std::cout << "OK[" << internalStorage[who].okTests << "], ";
    std::cout << "FAILED[" << internalStorage[who].failedTests << "], ";
    std::cout << "PENDING[" << internalStorage[who].pendingTests << "]";
    if(internalStorage[who].wtfTests != 0)
        std::cout << ", WTF??[" << internalStorage[who].wtfTests << "]";
    if(internalStorage[who].noOfTests == internalStorage[who].okTests)
        std::cout << " -- ALL OK!";
    std::cout << std::endl;
}
