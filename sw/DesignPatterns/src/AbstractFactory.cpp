#include "AbstractFactory.h"
#include "ServiceCar.h"


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
    return new ServiceNameSpace::CarSahara("CarSahara");
}


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
    return new ServiceNameSpace::CarSibir("CarSibir");
}


