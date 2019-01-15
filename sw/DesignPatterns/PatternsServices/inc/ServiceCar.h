#pragma once
#include "ServiceCarIf.h"


namespace ServiceNameSpace
{

class CarSahara : public ServiceNameSpace::CarIf
{
public:
    CarSahara(const std::string& name);
    
    ~CarSahara();
    
    // Mandatory
    void preInit();
    
    void postInit();
    
    std::string getObjectId();  // Constructor
    
    std::string getObjectName(); 
    //

    void setEngine(CarEngineIf* engine);
    
    void setWheel(CarWheelIf* wheel);
    
private:
std::string m_name;
static const std::string objectID;

CarEngineIf* m_engine;
CarWheelIf* m_wheel;
};


class CarSibir : public ServiceNameSpace::CarIf
{
public:
    CarSibir(const std::string& name);
    
    ~CarSibir();
    
    // Mandatory
    void preInit();
    
    void postInit();
    
    std::string getObjectId();  // Constructor
    
    std::string getObjectName(); 
    //

    void setEngine(CarEngineIf* engine);
    
    void setWheel(CarWheelIf* wheel);
    
private:
std::string m_name;
static const std::string objectID;

CarEngineIf* m_engine;
CarWheelIf* m_wheel;
};

} // End of namespace