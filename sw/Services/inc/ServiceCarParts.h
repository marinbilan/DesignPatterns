#pragma once
#include "ServiceCarPartsIf.h"


namespace ServiceNameSpace
{

class Engine : public ServiceNameSpace::CarPartsIf
{
public:
    Engine(const std::string& name);
    
    ~Engine();
    
    // Mandatory
    void preInit();
    
    void postInit();
    
    std::string getObjectId();  // Constructor
    
    std::string getObjectName();    // Token
    //

private:
std::string m_name;
static const std::string objectID;
};

class Wheel : public ServiceNameSpace::CarPartsIf
{
public:
    Wheel(const std::string& name);
    
    ~Wheel();
    
    // Mandatory
    void preInit();
    
    void postInit();
    
    std::string getObjectId();  // Constructor
    
    std::string getObjectName();    // Token
    //

private:
std::string m_name;
static const std::string objectID;
};

} // End of namespace