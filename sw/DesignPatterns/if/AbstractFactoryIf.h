#pragma once
#include "DesignPatternsBaseIf.h"

#include "ServiceCarPartsIf.h"


namespace DesignPatternsNamespace
{

class AbstractFactoryIf  : public DesignPatternsNamespace::DesignPatternsBaseIf
{
public:
    virtual ~AbstractFactoryIf() {}
  
    virtual std::string getName() = 0;

    virtual ServiceNameSpace::CarEngineIf* getEngine() = 0;
    
    virtual ServiceNameSpace::CarWheelIf* getWheel() = 0; 
};

} // End of namespace