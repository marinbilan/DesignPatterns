#pragma once
#include "ServiceBaseIf.h"
#include "Service1If.h"
#include "Service1.h"


// For unitTest exercise
class ScanIF
{
public:
    virtual ~ScanIF() {}
    virtual void displayAllFiles(std::string& str) {};
    virtual void f(std::string&) {};
};




namespace ServiceNameSpace
{

class Service0If  : public ServiceNameSpace::ServiceBaseIf
{
public:
    virtual ~Service0If()
    {
        std::cout << "[Service0If] Virtual Service0If destructor called" << std::endl;
    }
    
    // Mandatory for each service
    virtual void preInit() = 0;
    
    virtual void postInit() = 0;
  
    virtual std::string getObjectId() = 0;
    
    virtual std::string getObjectName()  = 0;
    //
    
    virtual void setService1If(Service1If* service1IfPrt) = 0;

    virtual std::vector<std::string> sampleInsertElement(std::string inputString, int position) = 0;

    virtual void findFilesInHomeDrive(ScanIF& scanObject) = 0;

    virtual std::vector<std::string> getVectorOfDummyStrings() = 0;

    virtual std::string getDummyString() = 0;
       
    virtual std::string findFileStat() = 0;

    virtual std::string findFileStatTest() = 0;
    
    // Template functions
    template<typename T1, typename T2>
    void FindDuplicates(std::vector<T1> vectorParam, T2& result)
    {
        int count = 0;
        for(int nIndex = 0; nIndex < (vectorParam.size()-1); ++nIndex)
        {
            if(vectorParam.at(nIndex) == vectorParam.at(nIndex+1))
            {
                count++;
                result = vectorParam.at(nIndex);
            }
        }
    }
    
    //
    // unit Test
    //
    virtual int unitTest0(std::string& str) = 0;

};

} // End of namespace