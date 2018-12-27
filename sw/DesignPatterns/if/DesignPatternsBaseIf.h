#pragma once
#include <iostream>
#include <string>
#include <map>

#include "DefaultDriver.h"


namespace DesignPatternsNamespace
{

class DesignPatternsBaseIf
{
public:
    virtual ~DesignPatternsBaseIf() 
    {
        std::cout << "[DesignPatternsBaseIf] Virtual DesignPatternsBaseIf destructor called" << std::endl;
    }
  
    virtual std::string getName() = 0;
};

}   // End of namespace