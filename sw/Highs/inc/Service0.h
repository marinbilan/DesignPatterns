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
 
    // Set   
    void setService1If(Service1If* service1IfPrt);

    // Get

    virtual int returnInt(int intInput);    
    
    virtual void setRefInt(int& intRefInput) ;
    
    virtual bool mockInMethod0();
    
    int unitTest0(std::string& str);

    std::vector<std::string> sampleInsertElement(std::string inputString, int position);

    void findFilesInHomeDrive(ScanIF& scanObject); 
 
    std::string getDummyString();
 
    std::vector<std::string> getVectorOfDummyStrings();

    std::string findFileStat();
    
    std::string findFileStatTest();

private:
std::string m_name;
std::vector<std::string> m_vector0 = {};

static const std::string objectID;
Service1If* m_ScanRef; 
};

} // End of namespace