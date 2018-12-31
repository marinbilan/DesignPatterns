#pragma once
#include "ServiceBaseIf.h"


namespace ServiceNameSpace
{

class CarPartsIf  : public ServiceNameSpace::ServiceBaseIf
{
public:
    virtual ~CarPartsIf()
    {
        std::cout << "[CarPartsIf] Virtual CarPartsIf destructor called" << std::endl;
    }
    
    // Mandatory for each service
    virtual void preInit() = 0;
    
    virtual void postInit() = 0;
  
    virtual std::string getObjectId() = 0;
    
    virtual std::string getObjectName()  = 0;
    //
    
};

} // End of namespace