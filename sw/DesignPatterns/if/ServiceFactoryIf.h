#pragma once
#include "DesignPatternsBaseIf.h"


namespace DesignPatternsNamespace
{

class ServiceFactoryIf  : public DesignPatternsNamespace::DesignPatternsBaseIf
{
public:
    virtual ~ServiceFactoryIf() {}
  
    virtual std::string getName() = 0;

};

} // End of namespace