#include "ServiceFactory.h"


const std::string DesignPatternsNamespace::ServiceFactory::objectID= "ServiceFactory"; 

DesignPatternsNamespace::ServiceFactory::ServiceFactory()
{
    std::cout << "[ServiceFactory][ServiceFactory()] Constructor called" << std::endl;
}


DesignPatternsNamespace::ServiceFactory::~ServiceFactory()
{
    std::cout << "[ServiceFactory] Destructor called" << std::endl;
}

std::string DesignPatternsNamespace::ServiceFactory::getName()
{
    return objectID;
}