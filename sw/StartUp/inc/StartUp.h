#pragma once
#include "StartUpIf.h"

#include "Container.h"
#include "ServiceFactory.h"
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

private:
static const std::string objectID;
};

} // End of namespace