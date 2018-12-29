#pragma once
#include "StartUpBaseIf.h"
#include "ServiceBaseIf.h"


namespace StartUpNameSpace
{

class StartUpIf  : public StartUpBaseIf
{
public:
    virtual ~StartUpIf() {}
  
    virtual std::string getName() = 0;
    
    virtual void init() = 0;
    
    virtual void registerAllServices() = 0;
    
    virtual void createAllServiceInstances() = 0;
    
    virtual void registerServiceInContainer(const std::string& serviceType, ServiceNameSpace::ServiceBaseIf* serviceBaseIf) = 0;

    virtual void sandBox() = 0;
};

}