#pragma once
#include "DefaultDriver.h"


namespace DriverNameSpace
{

class Driver0If  : public DriverNameSpace::DefaultDriver
{
public:
    virtual ~Driver0If()
    {
        std::cout << "[Driver0If] Virtual Driver0If destructor called" << std::endl;
    }
    
    virtual void init()
	{
		std::cout << "Calling init() from class Driver0If" << std::endl;
	}
    
};

}   // End of  namespace