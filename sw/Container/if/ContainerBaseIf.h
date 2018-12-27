#pragma once
#include <iostream>
#include <map>

#include "ServiceBaseIf.h"


namespace ContainerNameSpace
{

class ContainerBaseIf
{
public:
    virtual ~ContainerBaseIf() 
    {
        std::cout << "[ContainerBaseIf][~ContainerBaseIf]" << std::endl;
    }

    virtual std::string getName() = 0;
};

} // End of namespace