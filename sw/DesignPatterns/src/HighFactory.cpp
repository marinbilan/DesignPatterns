#include "HighFactory.h"


const std::string DesignPatternsNamespace::HighFactory::objectID= "HighFactory"; 

DesignPatternsNamespace::HighFactory::HighFactory()
{
    std::cout << "[HighFactory][HighFactory()] Constructor called" << std::endl;
}


DesignPatternsNamespace::HighFactory::~HighFactory()
{
    std::cout << "[HighFactory] Destructor called" << std::endl;
}

std::string DesignPatternsNamespace::HighFactory::getName()
{
    return objectID;
}