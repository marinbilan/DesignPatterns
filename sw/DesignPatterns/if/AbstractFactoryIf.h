#pragma once
#include "DesignPatternsBaseIf.h"
#include "ServiceCarIf.h"


namespace DesignPatternsNamespace
{

class AbstractFactoryIf  : public DesignPatternsNamespace::DesignPatternsBaseIf
{
public:
    virtual ~AbstractFactoryIf() {}
  
    virtual std::string getName() = 0;
    
    virtual ServiceNameSpace::CarIf* getCar() = 0;

};

} // End of namespace