#include "ServiceCarParts.h"


//
// EngineSahara
//
const std::string ServiceNameSpace::EngineSahara::objectID= "ServiceNameSpace::EngineSahara"; 


ServiceNameSpace::EngineSahara::EngineSahara(const std::string& name) : m_name(name)
{
    std::cout << "[EngineSahara][EngineSahara(const std::string& name)] Constructor called" << std::endl;
} 


ServiceNameSpace::EngineSahara::~EngineSahara()
{
    std::cout << "[EngineSahara][~EngineSahara] Destructor called" << std::endl;
}


void ServiceNameSpace::EngineSahara::preInit()
{
    std::cout << "[EngineSahara][preInit] get some database entries" << std::endl;
}


void ServiceNameSpace::EngineSahara::postInit()
{
    std::cout << "[EngineSahara][postInit] get ptrs on other services" << std::endl;
}


std::string ServiceNameSpace::EngineSahara::getObjectId()
{
    std::cout << "[EngineSahara][getObjectId] OK" << std::endl;
    return objectID;
}


std::string ServiceNameSpace::EngineSahara::getObjectName()
{
    std::cout << "[EngineSahara][getObjectName] OK" << std::endl;
    return m_name;
}


//
// EngineSibir
//
const std::string ServiceNameSpace::EngineSibir::objectID= "ServiceNameSpace::EngineSibir"; 


ServiceNameSpace::EngineSibir::EngineSibir(const std::string& name) : m_name(name)
{
    std::cout << "[EngineSibir][EngineSibir(const std::string& name)] Constructor called" << std::endl;
} 


ServiceNameSpace::EngineSibir::~EngineSibir()
{
    std::cout << "[EngineSibir][~EngineSibir] Destructor called" << std::endl;
}


void ServiceNameSpace::EngineSibir::preInit()
{
    std::cout << "[EngineSibir][preInit] get some database entries" << std::endl;
}


void ServiceNameSpace::EngineSibir::postInit()
{
    std::cout << "[EngineSibir][postInit] get ptrs on other services" << std::endl;
}


std::string ServiceNameSpace::EngineSibir::getObjectId()
{
    std::cout << "[EngineSibir][getObjectId] OK" << std::endl;
    return objectID;
}


std::string ServiceNameSpace::EngineSibir::getObjectName()
{
    std::cout << "[EngineSibir][getObjectName] OK" << std::endl;
    return m_name;
}


//
// WheelSahara
//
const std::string ServiceNameSpace::WheelSahara::objectID= "ServiceNameSpace::WheelSahara"; 


ServiceNameSpace::WheelSahara::WheelSahara(const std::string& name) : m_name(name)
{
    std::cout << "[WheelSahara][WheelSahara(const std::string& name)] Constructor called" << std::endl;
} 


ServiceNameSpace::WheelSahara::~WheelSahara()
{
    std::cout << "[WheelSahara][~WheelSahara] Destructor called" << std::endl;
}


void ServiceNameSpace::WheelSahara::preInit()
{
    std::cout << "[WheelSahara][preInit] get some database entries" << std::endl;
}


void ServiceNameSpace::WheelSahara::postInit()
{
    std::cout << "[WheelSahara][postInit] get ptrs on other services" << std::endl;
}


std::string ServiceNameSpace::WheelSahara::getObjectId()
{
    std::cout << "[WheelSahara][getObjectId] OK" << std::endl;
    return objectID;
}


std::string ServiceNameSpace::WheelSahara::getObjectName()
{
    std::cout << "[WheelSahara][getObjectName] OK" << std::endl;
    return m_name;
}


//
// WheelSibir
//
const std::string ServiceNameSpace::WheelSibir::objectID= "ServiceNameSpace::WheelSibir"; 


ServiceNameSpace::WheelSibir::WheelSibir(const std::string& name) : m_name(name)
{
    std::cout << "[WheelSibir][WheelSibir(const std::string& name)] Constructor called" << std::endl;
} 


ServiceNameSpace::WheelSibir::~WheelSibir()
{
    std::cout << "[WheelSibir][~WheelSibir] Destructor called" << std::endl;
}


void ServiceNameSpace::WheelSibir::preInit()
{
    std::cout << "[WheelSibir][preInit] get some database entries" << std::endl;
}


void ServiceNameSpace::WheelSibir::postInit()
{
    std::cout << "[WheelSibir][postInit] get ptrs on other services" << std::endl;
}


std::string ServiceNameSpace::WheelSibir::getObjectId()
{
    std::cout << "[WheelSibir][getObjectId] OK" << std::endl;
    return objectID;
}


std::string ServiceNameSpace::WheelSibir::getObjectName()
{
    std::cout << "[WheelSibir][getObjectName] OK" << std::endl;
    return m_name;
}