#pragma once
#include "StartUpIf.h"

#include "Container.h"
#include "HighFactory.h"
#include "DriverFactory.h"


namespace StartUpNameSpace
{

class StartUp : public StartUpNameSpace::StartUpIf
{
public:
    StartUp();
    ~StartUp();
    
    std::string getName();

    void init();
    
    void registerAllServices();
    
    void createAllServiceInstances();
    
    void registerServiceInContainer(const std::string& serviceType, ServiceNameSpace::ServiceBaseIf* serviceBaseIf);

    void sandBox();
    
    // Chapter 5
    // Item 30 - Familiatize yourself with perfect forwarding failure cases
    void modernEffectiveCpp_Chapter5_Item30();

private:
static const std::string objectID;
};

} // End of namespace