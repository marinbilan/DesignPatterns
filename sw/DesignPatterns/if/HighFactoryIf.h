#pragma once
#include "DesignPatternsBaseIf.h"


namespace DesignPatternsNamespace
{

class HighFactoryIf  : public DesignPatternsNamespace::DesignPatternsBaseIf
{
public:
    virtual ~HighFactoryIf() {}
  
    virtual std::string getName() = 0;

};

} // End of namespace