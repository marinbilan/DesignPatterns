#pragma once
#include "DesignPatternsBaseIf.h"


namespace DesignPatternsNamespace
{

class DriverFactoryIf  : public DesignPatternsNamespace::DesignPatternsBaseIf
{
public:
    virtual ~DriverFactoryIf() {}
  
    virtual std::string getName() = 0;

};

}   // End of namespace