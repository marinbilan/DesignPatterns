#pragma once
#include "ServiceBaseIf.h"


// Some dummy class for unitTest exercise
class FileStat
{
public:
int fileSize;
};




namespace ServiceNameSpace
{

class Service1If  : public ServiceNameSpace::ServiceBaseIf
{
public:
    virtual ~Service1If()
    {
        std::cout << "[Service1If] Virtual Service1If destructor called" << std::endl;
    }
    
    // Mandatory for each service
    virtual void preInit() = 0;
    
    virtual void postInit() = 0;
  
    virtual std::string getObjectId() = 0;
    
    virtual std::string getObjectName()  = 0;
    //
    
    virtual std::vector<std::string> getList() = 0;
    
    virtual std::vector<std::string>& getListRef() = 0;
    
    virtual void getFileStatistics(std::vector<std::string> vec, FileStat& stat) = 0;
    
    virtual void getFileStatistics2(std::vector<std::string>& filePath, FileStat* fileStat) = 0;

    //
    // unit Test
    //
    virtual int returnInt() = 0;
    
    virtual int returnInt0(int i, std::string& str) = 0;
};

} // End of namespace
