#include "ServiceCar.h"


// CarSahara
const std::string ServiceNameSpace::CarSahara::objectID= "ServiceNameSpace::CarSahara"; 


ServiceNameSpace::CarSahara::CarSahara(const std::string& name) : m_name(name)
{
    std::cout << "[CarSahara][CarSahara(const std::string& name)] Constructor called" << std::endl;
} 


ServiceNameSpace::CarSahara::~CarSahara()
{
    std::cout << "[CarSahara][~CarSahara] Destructor called" << std::endl;
}


void ServiceNameSpace::CarSahara::preInit()
{
    std::cout << "[CarSahara][preInit] get some database entries" << std::endl;
}


void ServiceNameSpace::CarSahara::postInit()
{
    std::cout << "[CarSahara][postInit] get ptrs on other services" << std::endl;
}


std::string ServiceNameSpace::CarSahara::getObjectId()
{
    std::cout << "[CarSahara][getObjectId] OK" << std::endl;
    return objectID;
}


std::string ServiceNameSpace::CarSahara::getObjectName()
{
    std::cout << "[CarSahara][getObjectName] OK" << std::endl;
    return m_name;
}


void ServiceNameSpace::CarSahara::setEngine(CarEngineIf* engine)
{
    std::cout << "[CarSahara][setEngine] OK" << std::endl;
    m_engine = engine;
}


void ServiceNameSpace::CarSahara::setWheel(CarWheelIf* wheel)
{
    std::cout << "[CarSahara][setWheel] OK" << std::endl;
    m_wheel = wheel;
}


// CarSibir
const std::string ServiceNameSpace::CarSibir::objectID= "ServiceNameSpace::CarSibir"; 


ServiceNameSpace::CarSibir::CarSibir(const std::string& name) : m_name(name)
{
    std::cout << "[CarSibir][CarSibir(const std::string& name)] Constructor called" << std::endl;
} 


ServiceNameSpace::CarSibir::~CarSibir()
{
    std::cout << "[CarSibir][~CarSibir] Destructor called" << std::endl;
}


void ServiceNameSpace::CarSibir::preInit()
{
    std::cout << "[CarSibir][preInit] get some database entries" << std::endl;
}


void ServiceNameSpace::CarSibir::postInit()
{
    std::cout << "[CarSibir][postInit] get ptrs on other services" << std::endl;
}


std::string ServiceNameSpace::CarSibir::getObjectId()
{
    std::cout << "[CarSibir][getObjectId] OK" << std::endl;
    return objectID;
}


std::string ServiceNameSpace::CarSibir::getObjectName()
{
    std::cout << "[CarSibir][getObjectName] OK" << std::endl;
    return m_name;
}


void ServiceNameSpace::CarSibir::setEngine(CarEngineIf* engine)
{
    std::cout << "[CarSibir][setEngine] OK" << std::endl;
    m_engine = engine;
}


void ServiceNameSpace::CarSibir::setWheel(CarWheelIf* wheel)
{
    std::cout << "[CarSibir][setWheel] OK" << std::endl;
    m_wheel = wheel;
}