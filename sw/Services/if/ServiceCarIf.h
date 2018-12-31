#pragma once
#include "ServiceBaseIf.h"


namespace ServiceNameSpace
{

class CarIf  : public ServiceNameSpace::ServiceBaseIf
{
public:
    virtual ~CarIf()
    {
        std::cout << "[CarIf] Virtual CarIf destructor called" << std::endl;
    }
    
    // Mandatory for each service
    virtual void preInit() = 0;
    
    virtual void postInit() = 0;
  
    virtual std::string getObjectId() = 0;
    
    virtual std::string getObjectName()  = 0;
    //
    
};

} // End of namespace