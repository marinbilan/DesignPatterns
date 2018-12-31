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
    
    ServiceNameSpace::CarIf* getCar();
    
private:
static const std::string objectID;

};

class AbstractFactorySibirCar : public DesignPatternsNamespace::AbstractFactoryIf
{
public:
    AbstractFactorySibirCar();
    
    ~AbstractFactorySibirCar();
    
    std::string getName();
    
    ServiceNameSpace::CarIf* getCar();
    
private:
static const std::string objectID;

};

} // End of namespace