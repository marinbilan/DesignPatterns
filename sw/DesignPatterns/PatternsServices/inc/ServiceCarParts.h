#pragma once
#include "ServiceCarPartsIf.h"


namespace ServiceNameSpace
{

class EngineSahara : public ServiceNameSpace::CarEngineIf
{
public:
    EngineSahara(const std::string& name);
    
    ~EngineSahara();
    
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


class EngineSibir : public ServiceNameSpace::CarEngineIf
{
public:
    EngineSibir(const std::string& name);
    
    ~EngineSibir();
    
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


class WheelSahara : public ServiceNameSpace::CarWheelIf
{
public:
    WheelSahara(const std::string& name);
    
    ~WheelSahara();
    
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


class WheelSibir : public ServiceNameSpace::CarWheelIf
{
public:
    WheelSibir(const std::string& name);
    
    ~WheelSibir();
    
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