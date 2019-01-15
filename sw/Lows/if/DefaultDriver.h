#pragma once
#include <iostream>


namespace DriverNameSpace
{

class DefaultDriver
{
public:
    virtual ~DefaultDriver() 
    {
        std::cout << "[DefaultDriver][~DefaultDriver]" << std::endl;
    }

	virtual void init()
	{
		std::cout << "Calling init() from class DefaultDriver" << std::endl;
	}

};

}   // End of  namespace