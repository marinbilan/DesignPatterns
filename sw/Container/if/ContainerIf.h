#pragma once
#include "ContainerBaseIf.h"


namespace ContainerNameSpace
{

class ContainerIf  : public ContainerNameSpace::ContainerBaseIf
{
public:
    virtual ~ContainerIf() {}
  
    virtual std::string getName() = 0;
    
    void registerService(const std::string& objName, ServiceNameSpace::ServiceBaseIf* service);

    ServiceNameSpace::ServiceBaseIf* getServiceFromContainer(const std::string& serviceName);
    
    void showAllServicesInContainer();
};

} // End of namespace