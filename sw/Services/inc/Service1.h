#pragma once
#include "Service1If.h"


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