#pragma once
#include "StartUpIf.h"

#include "Container.h"
#include "ServiceFactory.h"
#include "DriverFactory.h"


class Test
{
public:
    Test()
    {
        std::cout << "[Test] Constructor Test() called" << std::endl;
    }
 
    Test(const std::string& name) : m_name(name)
    {
        std::cout << "[Test] Constructor Test(const std::string& name) called" << std::endl;
    }
 
    Test(int id) : m_id(id)
    {
        std::cout << "[Test] Constructor Test(int id) called" << std::endl;
    }

    std::string& getName()
    {
        return m_name;
    }

    int getId()
    {
        return m_id;
    }
    
private:
std::string m_name;
int m_id;
};


namespace StartUpNameSpace
{

class StartUp : public StartUpNameSpace::StartUpIf
{
public:
    StartUp();
    ~StartUp();
    
    std::string getName();

    void init();

private:
static const std::string objectID;
};

} // End of namespace