#include "AbstractFactory.h"

#include "ServiceCar.h"
#include "ServiceCarParts.h"

//
// Sahara Car
//
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


ServiceNameSpace::CarIf* DesignPatternsNamespace::AbstractFactorySaharaCar::getCar()
{    
    // Create Car with specific parts
    ServiceNameSpace::CarIf* carSahara = new ServiceNameSpace::CarSahara("CarSahara");
    carSahara->setEngine(new ServiceNameSpace::EngineSahara("Sahara Engine"));
    carSahara->setWheel(new ServiceNameSpace::WheelSahara("Sahara Wheel"));
    
    return carSahara;
}


//
// Sibir Car
//
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


ServiceNameSpace::CarIf* DesignPatternsNamespace::AbstractFactorySibirCar::getCar()
{
    ServiceNameSpace::CarIf* CarSibir = new ServiceNameSpace::CarSibir("CarSibir");
    CarSibir->setEngine(new ServiceNameSpace::EngineSibir("Sibir Engine"));
    CarSibir->setWheel(new ServiceNameSpace::WheelSibir("Sibir Wheel"));
    
    return CarSibir;
}


