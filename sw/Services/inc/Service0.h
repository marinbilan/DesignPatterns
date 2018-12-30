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
    
    std::string getObjectId();  // Constructor
    
    std::string getObjectName();    // Token
    //
    
    void setService1If(Service1If* service1IfPrt);

    std::vector<std::string> sampleInsertElement(std::string inputString, int position);
    
    void findFilesInHomeDrive(ScanIF& scanObject); // Mock Test
    
    std::vector<std::string> getVectorOfDummyStrings();
    
    std::string getDummyString();
    
    std::string findFileStat();
    
    std::string findFileStatTest();
    
    //
    // unit Test
    //
    int unitTest0(std::string& str);

private:
std::string m_name;
std::vector<std::string> m_vector0 = {};

static const std::string objectID;
Service1If* m_ScanRef;  // unitTest 
};

} // End of namespace