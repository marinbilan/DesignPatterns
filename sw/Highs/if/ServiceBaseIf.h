#pragma once
#include <iostream>
#include <vector>


namespace ServiceNameSpace
{

class ServiceBaseIf
{
public:
    virtual ~ServiceBaseIf() 
    {
        std::cout << "[ServiceBaseIf][~ServiceBaseIf]" << std::endl;
    }

    // Mandatory for each service
    virtual void preInit() = 0;
    
    virtual void postInit() = 0;

    // /type (class/constructor name)
    virtual std::string getObjectId() = 0;

    // Constructor param (container search param)
    virtual std::string getObjectName() = 0;
    //
};

} // End of namespace