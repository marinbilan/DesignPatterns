#pragma once
#include "Service0If.h"


namespace ServiceNameSpace
{

class Service0 : public ServiceNameSpace::Service0If
{
public:
    Service0(const std::string& name);
    
    ~Service0();
    
    // Mandatory
    void preInit();
    
    void postInit();
    
    std::string getObjectId();
    
    std::string getObjectName();
    //

    std::vector<std::string> sampleInsertElement(std::string inputString, int position);
    
    void findFilesInHomeDrive(ScanIF& scanObject); // Mock Test
    
    std::vector<std::string> getVectorOfDummyStrings();
    
    std::string getDummyString();
    
    std::string findFileStat();
    
    std::string findFileStatTest();

private:
static const std::string objectID;
std::string m_name;

Service1If* m_ScanRef;  // unitTest 
};

} // End of namespace