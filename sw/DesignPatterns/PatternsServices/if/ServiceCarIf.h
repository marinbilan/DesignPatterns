#pragma once
#include "ServiceBaseIf.h"
#include "ServiceCarPartsIf.h"


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

    virtual void setEngine(CarEngineIf* engine)  = 0;
    
    virtual void setWheel(CarWheelIf* wheel)  = 0;
};

} // End of namespace