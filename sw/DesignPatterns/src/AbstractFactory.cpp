#include "AbstractFactory.h"

#include "ServiceCarParts.h"

// Sahara Car
const std::string DesignPatternsNamespace::AbstractFactorySaharaCar::objectID= "AbstractFactorySaharaCar"; 

DesignPatternsNamespace::AbstractFactorySaharaCar::AbstractFactorySaharaCar()
{
    std::cout << "[AbstractFactorySaharaCar][AbstractFactorySaharaCar()] Constructor called" << std::endl;
}


DesignPatternsNamespace::AbstractFactorySaharaCar::~AbstractFactorySaharaCar()
{
    std::cout << "[AbstractFactorySaharaCar] Destructor called" << std::endl;
}


std::string DesignPatternsNamespace::AbstractFactorySaharaCar::getName()
{
    return objectID;
}


ServiceNameSpace::CarEngineIf* DesignPatternsNamespace::AbstractFactorySaharaCar::getEngine()
{    
    ServiceNameSpace::CarEngineIf* engine = new ServiceNameSpace::EngineSahara("Sahara Engine");
    
    return engine;
}


ServiceNameSpace::CarWheelIf* DesignPatternsNamespace::AbstractFactorySaharaCar::getWheel()
{    
    ServiceNameSpace::CarWheelIf* wheel = new ServiceNameSpace::WheelSahara("Sahara Wheel");

    return wheel;
}


// Sibir Car
const std::string DesignPatternsNamespace::AbstractFactorySibirCar::objectID= "AbstractFactorySibirCar"; 

DesignPatternsNamespace::AbstractFactorySibirCar::AbstractFactorySibirCar()
{
    std::cout << "[AbstractFactorySibirCar][AbstractFactorySibirCar()] Constructor called" << std::endl;
}


DesignPatternsNamespace::AbstractFactorySibirCar::~AbstractFactorySibirCar()
{
    std::cout << "[AbstractFactorySibirCar] Destructor called" << std::endl;
}


std::string DesignPatternsNamespace::AbstractFactorySibirCar::getName()
{
    return objectID;
}


ServiceNameSpace::CarEngineIf* DesignPatternsNamespace::AbstractFactorySibirCar::getEngine()
{    
    ServiceNameSpace::CarEngineIf* engine = new ServiceNameSpace::EngineSibir("Sibir Engine");
    
    return engine;
}


ServiceNameSpace::CarWheelIf* DesignPatternsNamespace::AbstractFactorySibirCar::getWheel()
{    
    ServiceNameSpace::CarWheelIf* wheel = new ServiceNameSpace::WheelSibir("Sibir Wheel");

    return wheel;
}