#pragma once
#include "Service1If.h"

#include <gmock/gmock.h>
#include "gtest/gtest.h"

namespace ServiceNameSpace
{

class Service1 : public ServiceNameSpace::Service1If
{
public:
    Service1(const std::string& name);
    
    ~Service1();
    
    // Mandatory
    void preInit();
    
    void postInit();
    
    std::string getObjectId();
    
    std::string getObjectName();
    //

    std::vector<std::string> getList();

    std::vector<std::string>& getListRef();

    void getFileStatistics(std::vector<std::string> vec, FileStat& stat);
    
    void getFileStatistics2(std::vector<std::string>& filePath, FileStat* fileStat);
    
private:
static const std::string objectID;
std::string m_name;
};

} // End of namespace




class Service1Mock : public ServiceNameSpace::Service1If
{
public:
    MOCK_METHOD0(preInit, void());
    MOCK_METHOD0(postInit, void());
    MOCK_METHOD0(getObjectId, std::string());
    MOCK_METHOD0(getObjectName, std::string());

    MOCK_METHOD0(getList, std::vector<std::string>());
    MOCK_METHOD0(getListRef, std::vector<std::string>&());
    MOCK_METHOD2(getFileStatistics, void(std::vector<std::string>, FileStat&));
    MOCK_METHOD2(getFileStatistics2, void(std::vector<std::string>&, FileStat*));
};