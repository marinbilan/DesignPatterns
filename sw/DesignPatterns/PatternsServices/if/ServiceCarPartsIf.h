#pragma once
#include "ServiceBaseIf.h"


namespace ServiceNameSpace
{

class CarEngineIf  : public ServiceNameSpace::ServiceBaseIf
{
public:
    virtual ~CarEngineIf()
    {
        std::cout << "[CarEngineIf] Virtual CarEngineIf destructor called" << std::endl;
    }
    
    // Mandatory for each service
    virtual void preInit() = 0;
    
    virtual void postInit() = 0;
  
    virtual std::string getObjectId() = 0;
    
    virtual std::string getObjectName()  = 0;
    //
};


class CarWheelIf  : public ServiceNameSpace::ServiceBaseIf
{
public:
    virtual ~CarWheelIf()
    {
        std::cout << "[CarWheelIf] Virtual CarWheelIf destructor called" << std::endl;
    }
    
    // Mandatory for each service
    virtual void preInit() = 0;
    
    virtual void postInit() = 0;
  
    virtual std::string getObjectId() = 0;
    
    virtual std::string getObjectName()  = 0;
    //
}; 

} // End of namespace