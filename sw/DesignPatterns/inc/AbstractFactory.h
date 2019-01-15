#pragma once
#include "AbstractFactoryIf.h"


namespace DesignPatternsNamespace
{

class AbstractFactorySaharaCar : public DesignPatternsNamespace::AbstractFactoryIf
{
public:
    AbstractFactorySaharaCar();
    
    ~AbstractFactorySaharaCar();
    
    std::string getName();
    
    ServiceNameSpace::CarEngineIf* getEngine();
    
    ServiceNameSpace::CarWheelIf* getWheel(); 
    
private:
static const std::string objectID;

ServiceNameSpace::CarEngineIf* m_engine;
ServiceNameSpace::CarWheelIf* m_wheel; 
};


class AbstractFactorySibirCar : public DesignPatternsNamespace::AbstractFactoryIf
{
public:
    AbstractFactorySibirCar();
    
    ~AbstractFactorySibirCar();
    
    std::string getName();
    
    ServiceNameSpace::CarEngineIf* getEngine();
    
    ServiceNameSpace::CarWheelIf* getWheel(); 
    
private:
static const std::string objectID;

ServiceNameSpace::CarEngineIf* m_engine;
ServiceNameSpace::CarWheelIf* m_wheel; 
};

} // End of namespace