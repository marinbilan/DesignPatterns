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
    
    virtual std::vector<std::string> getList()
    {
        std::cout << "[Service1If][getList] warning ... Not implemented function ..." << std::endl;
        
        std::string str0("Error");
        std::vector<std::string> vec;
        vec.push_back(str0);
        
        return vec;
    }  
    
    virtual std::vector<std::string>& getListRef()
    {
        std::cout << "[Service1If][getListRef] warning ... Not implemented function ..." << std::endl;
        
        std::string str0("Error");
        std::vector<std::string> vec;
        vec.push_back(str0);
        
        return vec;
    }  
    
    virtual void getFileStatistics(std::vector<std::string> vec, FileStat& stat)
    {
        std::cout << "[Service1If][getFileStatistics] warning ... Not implemented function ..." << std::endl;
    }  
    
    virtual void getFileStatistics2(std::vector<std::string>& filePath, FileStat* fileStat)
    {
        std::cout << "[Service1If][getFileStatistics2] warning ... Not implemented function ..." << std::endl;
    } 
};

} // End of namespace



// TODO
// ------------------------------------------------ Service 1 MOCK ------------------------------------------------
/*class CScanMock : public ScanRefIF
{
public:
    MOCK_METHOD0(getList, std::vector<std::string>());
    MOCK_METHOD0(getListRef, std::vector<std::string>&());
    MOCK_METHOD2(getFileStatistics, void(std::vector<std::string>, FileStat&));
    MOCK_METHOD2(getFileStatistics2, void(std::vector<std::string>&, FileStat*));
};*/
// ------------------------------------------------ ------------------------------------------------