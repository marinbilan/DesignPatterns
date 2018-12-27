#pragma once
#include <iostream>


class StartUpBaseIf
{
public:
    virtual ~StartUpBaseIf() 
    {
        std::cout << "[StartUpBaseIf] Virtual StartUpBaseIf destructor called" << std::endl;
    }
  
    virtual std::string getName() = 0;
};