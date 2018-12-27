#pragma once
#include "ServiceBaseIf.h"
#include "Service1If.h"


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

    virtual std::vector<std::string> sampleInsertElement(std::string inputString, int position)
    {
        std::cout << "[Service0If][sampleInsertElement] warning ... Not implemented function ..." << std::endl;
    }    
    
    virtual void findFilesInHomeDrive(ScanIF& scanObject) // Mock Test
    {
        std::cout << "[Service0If][findFilesInHomeDrive] warning ... Not implemented function ..." << std::endl;
    } 

    virtual std::vector<std::string> getVectorOfDummyStrings()
    {
        std::cout << "[Service0If][getVectorOfDummyStrings] warning ... Not implemented function ..." << std::endl;
    } 

    virtual std::string getDummyString()
    {
        std::cout << "[Service0If][getDummyString] warning ... Not implemented function ..." << std::endl;
        std::string err("Error");
        return err;
    } 
       
    virtual std::string findFileStat()
    {
        std::cout << "[Service0If][findFileStat] warning ... Not implemented function ..." << std::endl;
        std::string err("Error");
        return err;
    } 

    virtual std::string findFileStatTest()
    {
        std::cout << "[Service0If][findFileStatTest] warning ... Not implemented function ..." << std::endl;
        std::string err("Error");
        return err;
    } 

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

};

} // End of namespace