#pragma once
#include "ServiceBaseIf.h"


namespace Chapter5NameSpace
{

class Chapter5If : public ServiceNameSpace::ServiceBaseIf
{
public:
    virtual ~Chapter5If()
    {
        std::cout << "[Chapter5If] Virtual Chapter5If destructor called" << std::endl;
    }
    
    // ServiceBaseIf - Mandatory for each service
    virtual void preInit() = 0;
    
    virtual void postInit() = 0;
  
    virtual std::string getObjectId() = 0;
    
    virtual std::string getObjectName()  = 0;
    //
};

} // End of namespace
