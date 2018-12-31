#pragma once
#include "DesignPatternsBaseIf.h"


namespace DesignPatternsNamespace
{

class BuilderPatternIf  : public DesignPatternsNamespace::DesignPatternsBaseIf
{
public:
    virtual ~BuilderPatternIf() {}
  
    virtual std::string getName() = 0;
    
    virtual void printProductInfo() = 0;
    
    virtual void print() = 0;

};

} // End of namespace