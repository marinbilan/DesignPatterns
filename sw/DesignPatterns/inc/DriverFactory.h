#pragma once
#include "DriverFactoryIf.h"


using CreatorFunction = DriverNameSpace::DefaultDriver*(*)(void); // define type of the function pointer
typedef std::map<std::string, CreatorFunction> DriversMap;
typedef std::map<std::string, DriverNameSpace::DefaultDriver*> ObjectsMap;

#define REGISTER_DRIVER_IN_DRV_FACTORY(x) bool x::registeredInDrvFactory = \
					DesignPatternsNamespace::DriverFactory::create().registerDriver(#x, &x::creator);


namespace DesignPatternsNamespace
{
    
class DriverFactory : public DesignPatternsNamespace::DriverFactoryIf
{
public:
    DriverFactory();
    ~DriverFactory();
    
    std::string getName();
    
    static DriverFactory& create();
	
    bool registerDriver(std::string driverType, CreatorFunction pCreateFunction);
	
    void createInstance(std::string driverType);
	
    DriverNameSpace::DefaultDriver* getInstance(std::string driverType);
    
private:
static const std::string objectID;

DriversMap driversMap;
ObjectsMap objectsMap;
};

} // End of namespace