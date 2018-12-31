#include "ServiceCarParts.h"

// Engine
const std::string ServiceNameSpace::Engine::objectID= "ServiceNameSpace::Engine"; 


ServiceNameSpace::Engine::Engine(const std::string& name) : m_name(name)
{
    std::cout << "[Engine][Engine(const std::string& name)] Constructor called" << std::endl;
} 


ServiceNameSpace::Engine::~Engine()
{
    std::cout << "[Engine][~Engine] Destructor called" << std::endl;
}


void ServiceNameSpace::Engine::preInit()
{
    std::cout << "[Engine][preInit] get some database entries" << std::endl;
}


void ServiceNameSpace::Engine::postInit()
{
    std::cout << "[Engine][postInit] get ptrs on other services" << std::endl;
}


std::string ServiceNameSpace::Engine::getObjectId()
{
    std::cout << "[Engine][getObjectId] OK" << std::endl;
    return objectID;
}


std::string ServiceNameSpace::Engine::getObjectName()
{
    std::cout << "[Engine][getObjectName] OK" << std::endl;
    return m_name;
}




// Wheel
const std::string ServiceNameSpace::Wheel::objectID= "ServiceNameSpace::Wheel"; 


ServiceNameSpace::Wheel::Wheel(const std::string& name) : m_name(name)
{
    std::cout << "[Wheel][Wheel(const std::string& name)] Constructor called" << std::endl;
} 


ServiceNameSpace::Wheel::~Wheel()
{
    std::cout << "[Wheel][~Wheel] Destructor called" << std::endl;
}


void ServiceNameSpace::Wheel::preInit()
{
    std::cout << "[Wheel][preInit] get some database entries" << std::endl;
}


void ServiceNameSpace::Wheel::postInit()
{
    std::cout << "[Wheel][postInit] get ptrs on other services" << std::endl;
}


std::string ServiceNameSpace::Wheel::getObjectId()
{
    std::cout << "[Wheel][getObjectId] OK" << std::endl;
    return objectID;
}


std::string ServiceNameSpace::Wheel::getObjectName()
{
    std::cout << "[Wheel][getObjectName] OK" << std::endl;
    return m_name;
}