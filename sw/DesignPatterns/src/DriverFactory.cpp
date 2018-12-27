#include "DriverFactory.h"


const std::string DesignPatternsNamespace::DriverFactory::objectID= "DriverFactory"; 

DesignPatternsNamespace::DriverFactory::DriverFactory()
{
    std::cout << "[DriverFactory][DriverFactory()] Constructor called" << std::endl;
}


DesignPatternsNamespace::DriverFactory::~DriverFactory()
{
    std::cout << "[DriverFactory] Destructor called" << std::endl;
}

std::string DesignPatternsNamespace::DriverFactory::getName()
{
    return objectID;
}


DesignPatternsNamespace::DriverFactory&  DesignPatternsNamespace::DriverFactory::create()
{
	static DriverFactory singletoneDriverFactory;
	return singletoneDriverFactory;
}

bool DesignPatternsNamespace::DriverFactory::registerDriver(std::string driverType, CreatorFunction pCreateFunction)
{
	if (driversMap.find(driverType) == driversMap.end()) 
	{
		driversMap[driverType] = pCreateFunction;
		return true;
	} 
	else {
		std::cout << "Driver already registered in Driver Factory" << std::endl;
		return false;
	}
}

void DesignPatternsNamespace::DriverFactory::createInstance(std::string driverType)
{
	auto driver = driversMap.find(driverType);
	if (driver != driversMap.end())
	{
		DriverNameSpace::DefaultDriver* newDriver = driver->second(); //calling through function pointer
		objectsMap[driverType] = newDriver;
	}
	else
	{
		std::cout << "No registered driver in Driver Factory" << std::endl;
	}
}

DriverNameSpace::DefaultDriver* DesignPatternsNamespace::DriverFactory::getInstance(std::string driverType)
{
	auto driverObject = objectsMap.find(driverType);
	if (!(driverObject == objectsMap.end()))
	{
		return driverObject->second;
	}

	return NULL;
} 